/* 
   Simple Pthread Program to illustrate the create/join threads.
   Author: Purushotham Bangalore
   Date: Jan 25, 2009

   To Compile: gcc -O -Wall pthread2.c -lpthread
   To Run: ./a.out 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int nthreads;

void *compute(void *arg) {
  long tid = (long)arg;
  pthread_t pthread_id = pthread_self();

  printf("Hello, I am thread %ld of %d, pthread_self() = %lu (0x%lx)\n", 
         tid, nthreads, (unsigned long)pthread_id, (unsigned long)pthread_id);

  return (NULL);
}

int main(int argc, char **argv) {
  long i;
  pthread_t *tid;
  pthread_t pthread_id = pthread_self();

  if (argc != 2) {
    printf("Usage: %s <# of threads>\n",argv[0]);
    exit(-1);
  }

  nthreads = atoi(argv[1]); // no. of threads

  // allocate vector and initialize
  tid = (pthread_t *)malloc(sizeof(pthread_t)*nthreads);

  // create threads
  for ( i = 0; i < nthreads; i++)
    pthread_create(&tid[i], NULL, compute, (void *)i);
    
  for ( i = 0; i < nthreads; i++)
    printf("tid[%ld] = %lu (0x%lx)\n", i, tid[i], tid[i]);

  printf("Hello, I am main thread. pthread_self() = %lu (0x%lx)\n", 
         (unsigned long)pthread_id, (unsigned long)pthread_id);

  // wait for them to complete
  for ( i = 0; i < nthreads; i++)
    pthread_join(tid[i], NULL);
    
  printf("Exiting main program\n");

  return 0;
}



