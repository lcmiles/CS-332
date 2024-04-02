#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 32
#define MAX_JOBS 100

typedef enum { //enumeration to represent the status of a job
    RUNNING,
    WAITING,
    COMPLETED
} JobStatus;

typedef struct { //structure to represent a job
    int jobid;
    char command[MAX_COMMAND_LENGTH];
    JobStatus status;
} Job;

Job jobs[MAX_JOBS]; //array used to store job info
int job_count = 0;
int running_jobs = 0;
int cores;

typedef struct { //structure for implementing circular queue
    int size;
    int *buffer;
    int start;
    int end;
    int count;
} queue;

queue *job_queue; //pointer to job queue

queue *queue_init(int n) { 
    queue *q = (queue *)malloc(sizeof(queue)); //allocate memory for queue struct
    q->size = n; //set size of queue
    q->buffer = (int *)malloc(sizeof(int) * n); //allocate memory for queue buffer
    q->start = 0; //init starting index
    q->end = 0; //init end index
    q->count = 0; //init count of queue elements

    return q;
}

int queue_insert(queue *q, int item) { 
    if ((q == NULL) || (q->count == q->size)) //if there is no queue struct initialized or the queue is full
        return -1;

    q->buffer[q->end] = item; //insert the item at the end of the queue
    q->end = (q->end + 1) % q->size; //update the starting index
    q->count++; //decrement the count of the elements

    return q->count;
}

int queue_delete(queue *q) { 
    if ((q == NULL) || (q->count == 0)) //if the queue has not been initialized or the queue is empty
        return -1;

    int x = q->buffer[q->start]; //get the item at the start index
    q->start = (q->start + 1) % q->size; //update the start index
    q->count--; //decrement the count of elements 

    return x;
}

void queue_destroy(queue *q) { 
    free(q->buffer); //free the buffer memory
    free(q); //free the queue structure memory
}

void submitJob(char *command);
void show_jobs();

int main(int argc, char *argv[]) {
    if (argc != 2) { //if the incorrect number of args provided, print usage message
        fprintf(stderr, "Usage: %s <number_of_cores>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    cores = atoi(argv[1]); //get the number of cores from arg
    job_queue = queue_init(MAX_JOBS); //init queue with max numer of jobs macro

    while (1) {
        printf("Enter command> ");
        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin); //read input command from stdin
        command[strcspn(command, "\n")] = '\0'; //remove trailing newline

        if (strncmp(command, "submit", 6) == 0) { //call correct function based on command line args
            submitJob(command + 7); //call submitJob() skipping "submit "
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

void submitJob(char *command) {
    
    char *args[MAX_ARGS];
    int arg_count = 0;

    char *token = strtok(command, " "); //tokenize command by spaces
    while (token != NULL && arg_count < MAX_ARGS - 1) { //while there are tokens and the count of arguments is less than the max
        args[arg_count++] = token; //store each token as an argument 
        token = strtok(NULL, " "); //get the next token
    }
    args[arg_count] = NULL; //null terminate argument list

    
    if (running_jobs < cores) { //if the number of running_jobs is less than the number of cores
        int job_index = queue_insert(job_queue, job_count); //enqueue the job index
        if (job_index == -1) { //if the job index is -1 then the queue is full
            printf("Job queue is full. Cannot add new job.\n");
            return;
        }

        pid_t pid = fork(); //fork a new process
        if (pid == 0) { //if the pid is 0, then it is a child process
            //redirect output and error streams
            char out_file[20], err_file[20];
            sprintf(out_file, "%d.out", job_count);
            sprintf(err_file, "%d.err", job_count);
            freopen(out_file, "w", stdout);
            freopen(err_file, "w", stderr);

            execvp(args[0], args); //execute the command
            perror("execvp");
            exit(EXIT_FAILURE);
        } else if (pid > 0) { //parent process
            //update job information
            jobs[job_count].jobid = job_count + 1;
            strcpy(jobs[job_count].command, args[0]);
            jobs[job_count].status = RUNNING;
            running_jobs++;

            printf("job %d added to the queue\n", job_count + 1);
        } else { //fork failed
            perror("fork");
        }
    } else {
        printf("No available cores. Job %s is waiting.\n", args[0]);
        //update job information
        int job_index = queue_insert(job_queue, job_count);
        if (job_index != -1) {
            jobs[job_count].jobid = job_count + 1;
            strcpy(jobs[job_count].command, args[0]);
            jobs[job_count].status = WAITING;
        } else {
            printf("Job queue is full. Cannot add new job.\n");
        }
    }

    job_count++;
}

void show_jobs() {

    printf("jobid     command                                 status\n");

    if (running_jobs == 0) {
        return;
    }

    int queue_index = job_queue->start; //start traversal of queue with first element
    for (int i = 0; i < job_queue->count; i++) { //for each element in the queue
        int job_index = job_queue->buffer[queue_index]; //get the job index from the circular queue
        Job *job = &jobs[job_index]; //get info from job struct about that job index

        if (job->status == RUNNING) { //if the job is running
            int status;
            pid_t result = waitpid(-1, &status, WNOHANG); //returns 0 if a child process is still running
            if (result == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            } else if (result == 0) { //process is still running
                printf("%d        %s Running\n", job->jobid, job->command);
            } else { //process is terminated
                job->status = COMPLETED;
                running_jobs--; //decrement running_jobs counter
                printf("%d        %s Completed\n", job->jobid, job->command);
            }
        } else if (job->status == WAITING) { //job is waiting
            printf("%d        %s Waiting\n", job->jobid, job->command);
        }
        
        queue_index = (queue_index + 1) % job_queue->size; //iterates to next position in circular queue
    }
}