
/*
 *  Reader/Writer Problem -- possible starvation for Writers
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>

#include <pthread.h>
#include <semaphore.h>

#define MILLION   1000000

#define NREADERS  10
#define NWRITERS   3
#define NTHREADS (NREADERS + NWRITERS)

int nreaders = 0;
sem_t mutex;               // protect nreaders variable
sem_t roomEmpty;           // blocks when thread(s) are in critical section(s)

sem_t totalmutex;

long reader_total = 0, writer_total = 0;

void *threadReader(void *nothing);  // function for the reader thread
void *threadWriter(void *nothing);  // function for the writer thread

int main(int argc, char *argv[])
{
    pthread_t th[NTHREADS];            // pthread's thread data structure
    int numbers[NTHREADS];             // array with thread id's
    double x,y;

    sem_init(&totalmutex, 0, 1);       // protect access to reader and writer totals
    sem_init(&mutex, 0, 1);            // protect access to total
    sem_init(&roomEmpty, 0, 1);        // prevent writers from entering a non-empty room and
                                       // prevent readers from entering when a writer is in the room

    for(int i = 0 ; i < NTHREADS ; i++)
        numbers[i] = (i < NREADERS) ? i : i - NREADERS;  // x = y if condition else z

    for(int i = 0 ; i < NTHREADS ; i++)
        if(i < NREADERS)
            pthread_create(&th[i], 0, (void *) threadReader, &numbers[i]); 
        else
            pthread_create(&th[i], 0, (void *) threadWriter, &numbers[i]);

    for(int i = 0 ; i < NTHREADS ; i++)
        pthread_join(th[i], 0);
    
    printf("readers: %10.6lf\n", (double) reader_total / (double) (NREADERS * MILLION));
    printf("writers: %10.6lf\n", (double) writer_total / (double) (NWRITERS * MILLION));
    return 0;
}
long timediff(struct timeval *t2, struct timeval *t1)
{
    return MILLION * (t2->tv_sec - t1->tv_sec) + (t2->tv_usec - t1->tv_usec);
}
long my_wait(sem_t *s)
{
    struct timeval t1, t2;

    gettimeofday(&t1, 0);
    sem_wait(s);
    gettimeofday(&t2, 0);
    return timediff(&t2,&t1);
}
void *threadReader(void *nothing)
{
    int mynumber;
    long tot = 0;

    mynumber = *(int *) nothing;

    for(int iter=0;iter<10;iter++){
        usleep(random() % MILLION);  // simulate doing non-critical work

        tot += my_wait(&mutex);

            nreaders++;
            if(nreaders == 1)
                tot += my_wait(&roomEmpty);
        sem_post(&mutex);

        printf("reader %d has entered the critical section\n", mynumber);

// beginning of critical section

        usleep(random() % MILLION);  // simulate time to do work in critical section

// end of critical section

        printf("reader %d has left the critical section\n", mynumber);

        tot += my_wait(&mutex);
            nreaders--;
            if(nreaders == 0)
                sem_post(&roomEmpty);
        sem_post(&mutex);

    }
    sem_wait(&totalmutex);
        reader_total += tot;
    sem_post(&totalmutex);
    pthread_exit(0);
}


void *threadWriter(void *nothing)
{
    int mynumber;
    int tot = 0;

    mynumber = *(int *) nothing;

    for(int iter=0;iter<10;iter++){
        usleep(random() % MILLION);   // simulate doing non-critical work

        tot += my_wait(&roomEmpty);
            printf("writer %d has entered the critical section\n", mynumber);

// beginning of writer's critical section

            usleep(random() % MILLION);   // simulate doing work

// end of writer's critical section

        sem_post(&roomEmpty);

        printf("writer %d has left the critical section\n", mynumber);

    }

    sem_wait(&totalmutex);
        writer_total += tot;
    sem_post(&totalmutex);
    pthread_exit(0);
}

