/* Sample program to illustrate the use of function pointers */
/* This program is taken as is unmodified from the qsort man page. 
 * The program takes strings as command-line arguments and invokes 
 * qsort function provided by the C library to sort the given strings. 
 * The qsort function takes the comparison function as the last argument.
 * See man qsort for more details. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmpstringp(const void *p1, const void *p2)
{
    /* The actual arguments to this function are "pointers to
     * pointers to char", but strcmp(3) arguments are "pointers
     * to char", hence the following cast plus dereference */

    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int main(int argc, char *argv[])
{
    int j;

    if (argc < 2) {
     fprintf(stderr, "Usage: %s <string>...\n", argv[0]);
     exit(EXIT_FAILURE);
    }

    qsort(&argv[1], argc - 1, sizeof(char *), cmpstringp);

    for (j = 1; j < argc; j++)
        puts(argv[j]);
    exit(EXIT_SUCCESS);
}

