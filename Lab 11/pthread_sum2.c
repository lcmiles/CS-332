#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    double *a; //pointer to the array of a double
    double sum; //partial sum computed by thread
    int N; //total num of elements in the array
    int size; //total num of threads
    long tid; //thread id
} ThreadArgs;

void *compute(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg; //case thre argument to ThreadArgs struct

    int myStart, myEnd, myN, i;

    myN = args->N / args->size; //num elements per thread
    myStart = args->tid * myN; //start index for this thread
    myEnd = myStart + myN; //end index for this thread
    if (args->tid == (args->size - 1)) //adjust end index for last thread
        myEnd = args->N;

    printf("Thread %ld is processing numbers from %d to %d\n", args->tid + 1, myStart, myEnd);

    double mysum = 0.0;
    for (i = myStart; i < myEnd; i++)
        mysum += args->a[i]; //accumulate sum of elements assigned to this thread

    args->sum = mysum; //store the partial sum in the structure
    return NULL;
}


int main(int argc, char **argv) {
    long i;
    pthread_t *tid;
    double sum = 0.0;

    if (argc != 3) { //check if the correct number of arguments are provided
       printf("Usage: %s <# of elements> <# of threads>\n",argv[0]);
       exit(-1);
    }

    int N = atoi(argv[1]); // no. of elements
    int nthreads = atoi(argv[2]); // no. of threads

    double *a = (double *)malloc(sizeof(double) * N); //allocate memory
    for (i = 0; i < N; i++) //initialize the array with values 1 to N
        a[i] = (double)(i + 1);


    tid = (pthread_t *)malloc(sizeof(pthread_t) * nthreads); //create array to store thread id's
    ThreadArgs *args = (ThreadArgs *)malloc(sizeof(ThreadArgs) * nthreads); //create array to store thread args

    for (i = 0; i < nthreads; i++) { //create and launch threads based on args struct
        args[i].a = a;
        args[i].N = N;
        args[i].size = nthreads;
        args[i].tid = i;
        pthread_create(&tid[i], NULL, compute, &args[i]); //create thread
        pthread_join(tid[i], NULL); //wait for thread to complete before proceeeding
    }

    for (i = 0; i < nthreads; i++) //wait for all threads to complete
        pthread_join(tid[i], NULL);

    for (i = 0; i < nthreads; i++) //compute final sum
        sum += args[i].sum;
    
    printf("Sum calculated by threads: %g, Expected: %g\n",
           sum, ((double)N * (N + 1)) / 2);
    
    free(tid);
    free(a);
    free(args);

    return 0;
}