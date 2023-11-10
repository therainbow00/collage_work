
/*
 *  Reader/Writer Problem -- no starvation for writers (as a group)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <sys/time.h>

#define MILLION   5000000

#define NREADERS  13
#define NWRITERS   3
#define NTHREADS (NREADERS + NWRITERS)

int nreaders = 0;
sem_t mutex, roomEmpty, turnstile, totalmutex;

long reader_total = 0, writer_total = 0;

void *threadReader(void *nothing);
void *threadWriter(void *nothing);

int main(int argc, char *argv[])
{
    pthread_t th[NTHREADS];
    int numbers[NTHREADS];
    double x, y;

    sem_init(&totalmutex, 0, 1);
    sem_init(&turnstile, 0, 1);
    sem_init(&mutex, 0, 1);
    sem_init(&roomEmpty, 0, 1);

    for(int i = 0 ; i < NTHREADS ; i++)
        numbers[i] = (i < NREADERS) ? i : i - NREADERS;

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
    long total = 0;

    mynumber = *(int *) nothing;

    for(int reps = 0; reps < 10; reps++){
        usleep(random() % MILLION);

        total += my_wait(&turnstile);
        sem_post(&turnstile);

        total += my_wait(&mutex);
            nreaders++;
            if(nreaders == 1)
                total += my_wait(&roomEmpty);
        sem_post(&mutex);

        printf("reader %d has entered the critical section\n", mynumber);


        usleep(random() % MILLION);


        printf("reader %d has left the critical section\n", mynumber);

        total += my_wait(&mutex);
            nreaders--;
            if(nreaders == 0)
                sem_post(&roomEmpty);
        sem_post(&mutex);

    }
    sem_wait(&totalmutex);
        reader_total += total;
    sem_post(&totalmutex);
    pthread_exit(0);
}


void *threadWriter(void *nothing)
{
    int mynumber;
    long total = 0;

    mynumber = *(int *) nothing;

    for(int reps = 0; reps < 10; reps++){
        usleep(random() % MILLION);

        total += my_wait(&turnstile);
            total += my_wait(&roomEmpty);
        sem_post(&turnstile);
        
            printf("writer %d has entered the critical section\n", mynumber);

            usleep(random() % MILLION);

        sem_post(&roomEmpty);

        printf("writer %d has left the critical section\n", mynumber);

    }
    sem_wait(&totalmutex);
        writer_total += total;
    sem_post(&totalmutex);
    pthread_exit(0);
}
