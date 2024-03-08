/* Sample program to illustrate how to use signals to determine if
 * a child process stopped or terminated by using a signal handler for
 * SIGCHLD.
 * To Compile: gcc -Wall sigchild.c
 * To Run: ./a.out <command> [args]
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

pid_t pid;

static void sig_child(int signo) {
  int status;

  signal(signo, SIG_IGN); /* ignore other SIGINT signals */
  waitpid(pid, &status, WNOHANG); /* get child process status */
  if (WIFEXITED(status)) { /* child process terminated normally */
    printf("Child process exited with status = %d\n", WEXITSTATUS(status));
  } else { /* child process did not terminate normally */
    printf("Child process did not terminate normally!\n");
    /* look at the man page for wait (man 2 wait) to determine
       how the child process was terminated */
  }
  fflush(stdout);
  signal(signo, sig_child); /* reinstall the signal handler */
}

int main(int argc, char **argv) {

  if (argc < 2) {
    printf("Usage: %s <command> [args]\n", argv[0]);
    exit(-1);
  }

  pid = fork();
  if (pid == 0) { /* this is child process */
    execvp(argv[1], &argv[1]);
    perror("exec");
    exit(-1);
  } else if (pid > 0) { /* this is the parent process */
    /* setup signal handler to intercept SIGINT */
    if (signal(SIGCHLD, sig_child) == SIG_ERR) {
      printf("Unable to catch SIGCHLD\n");
    }
    printf("Wait for the child process to terminate\n");
    for ( ; ; )
      pause();
  } else { /* we have an error */
    perror("fork"); /* use perror to print the system error message */
    exit(EXIT_FAILURE);
  }
    
  printf("[%ld]: Exiting program .....\n", (long)getpid());

  return 0;
}
