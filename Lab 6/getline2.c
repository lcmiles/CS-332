/* Sample program to illustrate C standard library usage */
/* Version 2 - uses the getline function */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	char *line=NULL;
	FILE *fp;
	size_t maxlen=0;
	ssize_t n;

	printf("BUFSIZ = %d\n", BUFSIZ);

	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("Error opening file %s\n", argv[1]);
		exit(-1);
	}
	while ( (n = getline(&line, &maxlen, fp)) > 0)
		printf("%ld[%ld]: %s\n", n, maxlen, line);

	fclose(fp);
	return 0;
}

