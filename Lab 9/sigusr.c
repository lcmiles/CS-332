#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sigUsr(int signo) {
	if (signo == SIGUSR1) {
		printf("received SIGUSR1\n");
	} else if (signo == SIGUSR2) {
		printf("received SIGUSR2\n");
	} else {
		printf("received signal %d\n", signo);
	}
}

int main(void) {
	if (signal(SIGUSR1, sigUsr) == SIG_ERR) {
		printf("can't catch SIGUSR1\n");
		exit(-1);
	}
	if (signal(SIGUSR2, sigUsr) == SIG_ERR) {
		printf("can't catch SIGUSR2\n");
		exit(-1);
	}
	for ( ; ; )
		pause();

	return 0;
}
