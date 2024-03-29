#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

static pid_t child_pid;

static void sigUsr(int signo) { //signal handler function
    switch(signo) {
        case SIGINT: //handle interupt case (CTRL + C)
            printf("received SIGINT signal %d\n", signo);
            break;
        case SIGQUIT: //handle quit case (CTRL + \)
            printf("received SIGQUIT signal %d\n", signo);
            exit(EXIT_SUCCESS);
            break;
        case SIGTSTP: //handle quit case (CTRL + Z)
            printf("received SIGTSTP signal %d\n", signo);
            break;
        default: //handle other signals
            printf("received signal %d\n", signo);
    }
}

static void sigChld(int signo) { //handler function for SIGCHILD
    int status; //exit status of child process
    wait(&status); //wait for the child process to exit based on its status
    if (WIFEXITED(status)) { //if the child process exited normally
        printf("Child process exited with status = %d\n", WEXITSTATUS(status));
        exit(0);
    } else {
        printf("Child process did not terminate normally!\n");
    }
}

int main(int argc, char **argv) {
    pid_t pid;

    if (argc < 2) { 
        printf("Usage: %s <command> [args]\n", argv[0]);
        exit(EXIT_FAILURE); //exit with failure if command line arguments were not provided 
    }

    if (signal(SIGINT, sigUsr) == SIG_ERR ||
        signal(SIGTSTP, sigUsr) == SIG_ERR ||
        signal(SIGQUIT, sigUsr) == SIG_ERR ||
        signal(SIGCHLD, sigChld) == SIG_ERR) {
        printf("Error setting signal handlers\n");
        exit(EXIT_FAILURE); //exit with failure if signals were not set correctly
    }
    
    pid = fork(); //spawn child process
    if (pid == 0) { //if parent process
        execvp(argv[1], &argv[1]); //execute command provided as args
        printf("If you see this statement then execvp failed ;-(\n");
        perror("execvp");
        exit(EXIT_FAILURE); //exit with failure if execvp() failed
    } else if (pid > 0) { //if child process
        child_pid = pid; //set global pid to child pid
        printf("Wait for the child process to terminate\n");
        while(1) {
            pause(); //sleep until signal is received
        }
    } else {
        perror("fork");
        exit(EXIT_FAILURE); //exit with failure if fork() does not spawn a child process
    }
    
    printf("[%ld]: Exiting program .....\n", (long)getpid());

    return 0;
}
