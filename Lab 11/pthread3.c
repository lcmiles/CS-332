/* 
   Simple Pthread Program to illustrate the create/join threads
   by passing a structure as an argument to pthread_create.
   Author: Purushotham Bangalore
   Date: Jan 25, 2009

   To Compile: gcc -O -Wall pthread3.c -lpthread
   To Run: ./a.out 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct foo {
   pthread_t ptid;  /* thread id returned by pthread_create */
   int tid;         /* user managed thread id (0 through nthreads-1) */
   int nthreads;    /* total no. of threads created */
} FOO;

void *compute(void *args) {
  FOO *info = (FOO *)args;
  printf("Hello, I am thread %d of %d\n", info->tid, info->nthreads);

  return (NULL);
}

int main(int argc, char **argv) {
  int i, nthreads;
  FOO *info;

  if (argc != 2) {
    printf("Usage: %s <# of threads>\n",argv[0]);
    exit(-1);
  }

  nthreads = atoi(argv[1]); // no. of threads

  // allocate structure
  info = (FOO *)malloc(sizeof(FOO)*nthreads);

  // create threads
  for ( i = 0; i < nthreads; i++) {
    info[i].tid = i;
    info[i].nthreads = nthreads;
    pthread_create(&info[i].ptid, NULL, compute, (void *)&info[i]);
  }
    
  // wait for them to complete
  for ( i = 0; i < nthreads; i++)
    pthread_join(info[i].ptid, NULL);
    
  free(info);
  printf("Exiting main program\n");

  return 0;
}

