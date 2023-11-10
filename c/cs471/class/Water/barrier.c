
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#include "barrier.h"

BARRIER *init_barrier(int target)
{
    BARRIER *tmp;

    tmp = malloc(sizeof(BARRIER));   // alloc memory for BARRIER
    sem_init(&tmp->mutex, 0, 1);       // mutex = 1, so first thread gets through
    sem_init(&tmp->turnstile1, 0, 0);  // turnstile1 = 0, wait until 2 H's and 1 O are available
    sem_init(&tmp->turnstile2, 0, 1);  // turnstile2 = 1, makes starting setup same as others
    tmp->count = 0;
    tmp->target = target;
    return tmp;
}

void wait_barrier(BARRIER *barr, char *who)
{
    sem_wait(&barr->mutex);
        barr->count++;
        if(barr->count == barr->target){
            sem_wait(&barr->turnstile2);
            sem_post(&barr->turnstile1);
        }
    sem_post(&barr->mutex);

    sem_wait(&barr->turnstile1);
    sem_post(&barr->turnstile1);

    sem_wait(&barr->mutex);
        barr->count--;
        if(barr->count == 0){
            sem_wait(&barr->turnstile1);
            sem_post(&barr->turnstile2);
        }
    sem_post(&barr->mutex);

    sem_wait(&barr->turnstile2);
    sem_post(&barr->turnstile2);

}
