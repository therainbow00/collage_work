
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NTHREADS   2

// 1.

void *threadA(void *nothing);
void *threadB(void *nothing);

int main(int argc, char *argv[])
{
    pthread_t th[NTHREADS];

// 2.

    pthread_create(&th[0], 0, (void *) threadA, 0); 
    pthread_create(&th[1], 0, (void *) threadB, 0); 

    pthread_join(th[0], 0);
    pthread_join(th[1], 0);
 
    printf("\n");

    return 0;
}

void *threadA(void *nothing)
{
    
    for(int i=0;i<10;i++){

// 3.

        printf("A");

// 4.

    }

    pthread_exit(0);
}

void *threadB(void *nothing)
{
    
    for(int i=0;i<10;i++){

// 5.

        printf("B");

// 6.

    }

    pthread_exit(0);
}
