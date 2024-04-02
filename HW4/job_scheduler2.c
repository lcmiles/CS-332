#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 20
#define MAX_JOBS 100

// Define the job structure
typedef struct job {
    int id;
    char *command;
    struct job *next;
} Job;

Job *job_queue = NULL;
int job_count = 0;
int cores;

// Function prototypes
Job *new_job(int id, char *command);
void add_job(Job **queue, Job *j);
Job *remove_job(Job **queue);
void execute_next_job(Job **queue);
void submit_job(char *command);
void show_jobs();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_cores>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    cores = atoi(argv[1]);

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

    // Create a new job
    Job *new_job = malloc(sizeof(Job));
    new_job->id = job_count++;
    new_job->command = strdup(args[0]); // Copy the command string
    new_job->next = NULL;

    // Add the job to the queue
    add_job(&job_queue, new_job);

    // Fork a new process
    pid_t pid = fork();
    if (pid == 0) { // Child process
        // Execute the command
        execvp(args[0], args);
        perror("execvp"); // This should not return
        exit(EXIT_FAILURE);
    } else if (pid > 0) { // Parent process
        printf("job %d added to the queue\n", new_job->id);
    } else { // Fork failed
        perror("fork");
    }
}

void show_jobs() {
    printf("jobid command status\n");

    Job *current_job = job_queue;
    while (current_job != NULL) {
        // Check the status of the job
        int status;
        pid_t result = waitpid(-1, &status, WNOHANG);
        if (result == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        } else if (result == 0) {
            // Process is still running
            printf("%d %s %s\n", current_job->id, current_job->command, (current_job->id < cores) ? "Running" : "Waiting");
        } else {
            // Process has terminated
            printf("%d %s Completed\n", current_job->id, current_job->command);
        }
        current_job = current_job->next;
    }
}

// Create a new job
Job *new_job(int id, char *command) {
    Job *j = malloc(sizeof(Job));
    j->id = id;
    j->command = command;
    j->next = NULL;
    return j;
}

// Add a job to the queue
void add_job(Job **queue, Job *j) {
    if (*queue == NULL) {
        *queue = j;
    } else {
        Job *last = *queue;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = j;
    }
}

// Remove a job from the queue
Job *remove_job(Job **queue) {
    if (*queue == NULL) {
        return NULL;
    } else {
        Job *j = *queue;
        *queue = j->next;
        return j;
    }
}

// Execute the next job in the queue
void execute_next_job(Job **queue) {
    Job *j = remove_job(queue);
    if (j != NULL) {
        system(j->command);
        free(j->command); // Free the dynamically allocated command string
        free(j);
    }
}
