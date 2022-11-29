
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// 1. declare any variables you need
sem_t mutex;

void *thread2(void *nothing);

int main(int argc, char *argv[])
{
    pthread_t th[10];
    int idlist[10];

    for(int i=0;i<10;i++)
        idlist[i] = i+1;

// 2. initialize any variables you add to the program
    sem_init(&mutex, 0, 1);
// create the threads

    for(int i=0;i<10;i++){
        printf("creating thread %d with id %d\n", i, idlist[i]);
        pthread_create(&th[i], 0, (void *) thread2, (void *) &idlist[i]);
    }

// wait for all threads to finish

    for(int i=0;i<10;i++)
        pthread_join(th[i], 0);
    return 0;
}
void *thread2(void *nothing)
{
    int id;

    id = * ( int *) nothing;

// 3. add code to insure threads reach the print statement in order
    sem_wait(&mutex);
    printf("thread %d reporting in\n", id);

    sem_post(&mutex);

    pthread_exit(0);
}
