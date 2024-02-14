/* Sample program to illustrate C standard library usage */
/* Version 6 - same as version 5, except writes output to file using 
 * fprintf and also uses fprintf instead of printf to write to standard
 * output and standard error streams */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	char *line;
	FILE *fp, *fpout;

	line = malloc(sizeof(char)*BUFSIZ);

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr,"Error opening file %s\n", argv[1]);
		exit(-1);
	}
	if ((fpout = fopen(argv[2], "w")) == NULL) {
		fprintf(stderr,"Error opening file %s\n", argv[2]);
		exit(-1);
	}
	while ( fscanf(fp, "%s", line) != EOF )
		fprintf(fpout,"%ld: %s\n", strlen(line), line);

	fclose(fp);
	fclose(fpout);
	return 0;
}

