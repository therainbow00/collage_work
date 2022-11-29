
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <pthread.h>
#include <semaphore.h>

#define BILLION  1000000000
#define NPAIRS           10

sem_t mutex;
unsigned long flags;

void *receiver(void *nothing);
void *sender(void *nothing);

int main(int argc, char *argv[])
{
    pthread_t th[2*NPAIRS];
    int id[2*NPAIRS];

    for(int i=0;i<2*NPAIRS;i++)
        id[i] = i % NPAIRS;

    flags = 0;
    sem_init(&mutex, 0, 1);

    for(int i=0;i<2*NPAIRS;i++){
        if(i < NPAIRS)
            pthread_create(&th[i], 0, (void *) receiver, &id[i]);
        else
            pthread_create(&th[i], 0, (void *) sender, &id[i]);
    }
    for(int i = 0 ; i < 2*NPAIRS ; i++)
        pthread_join(th[i], 0);
    printf("flags = %lu, should be %u\n", flags, (1 << NPAIRS) - 1);
    return 0;
}
long getnanoseconds()
{
    struct timespec ts;

    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec * BILLION + ts.tv_nsec;
}
void *sender(void *nothing)
{
    int id;

    id = * (int *) nothing;

    usleep(random() % 5000000);   // simulate delay before sending

    sem_wait(&mutex);
        flags |= (1 << id);
        printf("S %02d %12ld\n", id, getnanoseconds());
    sem_post(&mutex);

    pthread_exit(0);
}

void *receiver(void *nothing)
{
    int id;

    id = * (int *) nothing;

/*
 * add code so that this receiver waits until the corresponding sender
 * has set the bit for the id.
 */

    printf("R %02d %12ld\n", id, getnanoseconds());

    pthread_exit(0);
}

