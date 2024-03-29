#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 32
#define MAX_JOBS 100

typedef enum {
    RUNNING,
    WAITING,
    COMPLETED
} JobStatus;

typedef struct {
    int jobid;
    char command[MAX_COMMAND_LENGTH];
    JobStatus status;
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;
int running_jobs = 0;
int cores;

/* Circular queue implementation */
typedef struct {
    int size;
    int *buffer;
    int start;
    int end;
    int count;
} queue;

queue *job_queue;

queue *queue_init(int n) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = n;
    q->buffer = (int *)malloc(sizeof(int) * n);
    q->start = 0;
    q->end = 0;
    q->count = 0;

    return q;
}

int queue_insert(queue *q, int item) {
    if ((q == NULL) || (q->count == q->size))
        return -1;

    q->buffer[q->end] = item;
    q->end = (q->end + 1) % q->size;
    q->count++;

    return q->count;
}

int queue_delete(queue *q) {
    if ((q == NULL) || (q->count == 0))
        return -1;

    int x = q->buffer[q->start];
    q->start = (q->start + 1) % q->size;
    q->count--;

    return x;
}

void queue_destroy(queue *q) {
    free(q->buffer);
    free(q);
}
/* End of Circular queue implementation */

void submit_job(char *command);
void show_jobs();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_cores>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    cores = atoi(argv[1]);
    job_queue = queue_init(MAX_JOBS);

    while (1) {
        printf("Enter command> ");
        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0'; // remove trailing newline

        if (strncmp(command, "submit", 6) == 0) {
            submit_job(command + 7); // skip "submit "
        } else if (strcmp(command, "showjobs") == 0) {
            show_jobs();
        } else if (strcmp(command, "exit") == 0) {
            exit(1);
        } else {
            printf("Unknown command\n");
        }
    }

    return 0;
}

void submit_job(char *command) {
    // Parse command and arguments
    char *args[MAX_ARGS];
    int arg_count = 0;

    char *token = strtok(command, " ");
    while (token != NULL && arg_count < MAX_ARGS - 1) {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    // Enqueue the job index
    int job_index = job_count++;
    queue_insert(job_queue, job_index);

    // Fork a new process
    pid_t pid = fork();
    if (pid == 0) { // Child process
        // Redirect output and error streams
        char out_file[20], err_file[20];
        sprintf(out_file, "%d.out", job_index + 1);
        sprintf(err_file, "%d.err", job_index + 1);
        freopen(out_file, "w", stdout);
        freopen(err_file, "w", stderr);

        // Execute the command
        execvp(args[0], args);
        perror("execvp"); // This should not return
        exit(EXIT_FAILURE);
    } else if (pid > 0) { // Parent process
        // Update job information
        jobs[job_index].jobid = job_index + 1;
        strcpy(jobs[job_index].command, args[0]);
        jobs[job_index].status = RUNNING;
        running_jobs++;

        printf("job %d added to the queue\n", job_index + 1);
    } else { // Fork failed
        perror("fork");
    }
}

void show_jobs() {
    printf("jobid command status\n");

    int queue_index = job_queue->start;
    for (int i = 0; i < job_queue->count; i++) {
        int job_index = job_queue->buffer[queue_index];
        Job *job = &jobs[job_index];
        
        // Check the status of the job
        int status;
        pid_t result = waitpid(-1, &status, WNOHANG);
        if (result == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        } else if (result == 0) {
            // Process is still running
            printf("%d %s %s\n", job->jobid, job->command, (i < cores) ? "Running" : "Waiting");
        } else {
            // Process has terminated
            job->status = COMPLETED;
            printf("%d %s Completed\n", job->jobid, job->command);
        }
        
        queue_index = (queue_index + 1) % job_queue->size;
    }
}



