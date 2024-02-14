/* Sample program to illustrate C standard library usage */
/* Version 3 - uses getdelim, similar to version 2, except that
 * we use space as the delimiter not newline */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	char *line=NULL;
	FILE *fp;
	size_t maxlen=0;
	ssize_t n;

	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("Error opening file %s\n", argv[1]);
		exit(-1);
	}
	while ( (n = getdelim(&line, &maxlen, ' ', fp)) > 0)
		printf("%ld: %s\n", n, line);

	fclose(fp);
	return 0;
}

