
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include "barrier.h"

#define NTHREADS 30

sem_t mutex, oqueue, hqueue;
BARRIER *barrier;
int noxygen, nhydrogen;

void bond(char *who);
void *thread_O(void *nothing);
void *thread_H(void *nothing);

int main(int argc, char *argv[])
{
    pthread_t th[NTHREADS];

    srandom(2);
    sem_init(&mutex, 0, 1);
    sem_init(&oqueue, 0, 0);
    sem_init(&hqueue, 0, 0);
    noxygen = nhydrogen = 0;
    barrier = init_barrier(3);

    for(int i=0;i<NTHREADS;i++){
        if(random() % 3 == 0){
            pthread_create(&th[i], 0, thread_O, 0);
        } else {
            pthread_create(&th[i], 0, thread_H, 0);
        }
    }
    for(int i=0;i<NTHREADS;i++)
        pthread_join(th[i], 0);
    return 0;
}
void bond(char *who)
{
    printf("%s is bonding\n", who);
}
void *thread_O(void *nothing)
{
    sem_wait(&mutex);
        noxygen++;
        if(nhydrogen >= 2){      //   && noxygen >= 1){
            sem_post(&hqueue);
            sem_post(&hqueue);
            sem_post(&oqueue);
            nhydrogen -= 2;
            noxygen -= 1;
        } else {
            sem_post(&mutex);
        }
     sem_wait(&oqueue);
     bond("oxygen");
     wait_barrier(barrier,"oxygen");
     sem_post(&mutex);
     pthread_exit(0);
}

void *thread_H(void *nothing)
{
    sem_wait(&mutex);
        nhydrogen++;
        if(nhydrogen >= 2 && noxygen >= 1){
            sem_post(&hqueue);
            sem_post(&hqueue);
            sem_post(&oqueue);
            nhydrogen -= 2;
            noxygen -= 1;
        } else {
            sem_post(&mutex);
        }
     sem_wait(&hqueue);
     bond("hydrogen");
     wait_barrier(barrier,"hydrogen");
     pthread_exit(0);
}

