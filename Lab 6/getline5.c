/* Sample program to illustrate C standard library usage */
/* Version 5 - uses fscanf */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	char *line;
	FILE *fp;

	line = malloc(sizeof(char)*BUFSIZ);

	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("Error opening file %s\n", argv[1]);
		exit(-1);
	}
	while ( fscanf(fp, "%s", line) != EOF )
		printf("%ld: %s\n", strlen(line), line);

	fclose(fp);
	return 0;
}

