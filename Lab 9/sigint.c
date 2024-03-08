#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sig_int(int signo) {
	ssize_t n;
	char buf[2];

	signal(signo, SIG_IGN); /* ignore signal first */
	printf("Do you really want to do this: [Y/N]? ");
	fflush(stdout);
	n = read(STDIN_FILENO, buf, 2);
	if ( buf[0] == 'Y' ) {
		raise(SIGTERM); // or kill(0, SIGTERM); // or exit (-1); 
	} else {
		printf("Ignoring signal, be careful next time!\n");
		fflush(stdout);
	}
	signal(signo, sig_int); /* reinstall the signal handler */
}

int main(void) {
	if (signal(SIGINT, sig_int) == SIG_ERR) {
		printf("Unable to catch SIGINT\n");
		exit(-1);
	}
	for ( ; ; )
		pause();

	return 0;
}
