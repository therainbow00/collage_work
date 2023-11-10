
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NTHREADS   2

sem_t await, bwait;

void *threadA(void *nothing);
void *threadB(void *nothing);

int main(int argc, char *argv[])
{
    pthread_t th[NTHREADS];

    sem_init(&await, 0, 1);
    sem_init(&bwait, 0, 0);

    pthread_create(&th[0], 0, (void *) threadA, 0); 
    pthread_create(&th[1], 0, (void *) threadB, 0); 

    pthread_join(th[0], 0);
    pthread_join(th[1], 0);
 
    printf("\n");

    return 0;
}

void *threadA(void *nothing)
{
    int value;
    for(int i = 0; i < 10; i++){

        sem_wait(&await);
        printf("A\n");
        sem_post(&bwait);

    }

    pthread_exit(0);
}

void *threadB(void *nothing)
{
    int value;
    for(int i = 0; i < 10; i++){

        sem_wait(&bwait);
        printf("B\n");
        sem_post(&await);

    }

    pthread_exit(0);
}
