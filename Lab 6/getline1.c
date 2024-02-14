/* Sample program to illustrate C standard library usage */
/* Version 1 - uses getc to read one element at a time and 
 * we implement our own version of getLine function. */
#include <stdio.h>
#include <stdlib.h>

int getLine(FILE *fp, char *line);

int main(int argc, char** argv) {
	char *str;
	FILE *fp;
	int n;

	str = malloc(sizeof(char)*BUFSIZ);

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
	//if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("Error opening file %s\n", argv[1]);
		exit(-1);
	}
	while ( (n = getLine(fp, str)) > 0)
		printf("%d: %s\n", n, str);

	fclose(fp);

	return 0;
}

int getLine(FILE *fp, char *line) {

	int c, i=0;
	while ((c = getc(fp)) != '\n' && c != EOF)
		line[i++] = c;
	line[i] = '\0';

	return i;
}

