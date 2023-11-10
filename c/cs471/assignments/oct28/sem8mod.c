
/*
 *  Reader/Writer Problem -- possible starvation for Writers
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

#define NREADERS  10
#define NWRITERS   3
#define NTHREADS (NREADERS + NWRITERS)

int nreaders = 0;
sem_t mutex;
sem_t roomEmpty;

void *threadReader(void *nothing);
void *threadWriter(void *nothing);

int main(int argc, char *argv[])
{
    pthread_t th[NTHREADS];
    int numbers[NTHREADS];
    double x, y;
    
    long reader_total = 0, writer_total = 0;
    
    struct timeval v3;
    gettimeofday(&v3, 0);
    long start = v3.tv_sec;
    
    long total;

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

    return 0;
}

void *threadReader(void *nothing)
{
    struct timeval v1, v2;
    gettimeofday(&v1, 0);
    int mynumber;

    mynumber = *(int *) nothing;
    
    long reader_time = 0;
    int reps;

    for(reps = 0; reps < 10; reps++){
        usleep(random() % MILLION);

        sem_wait(&mutex);
            nreaders++;
            if(nreaders == 1)
                sem_wait(&roomEmpty);
                gettimeofday(&v2, 0);
        gettimeofday(&v2, 0);

        sem_post(&mutex);


        usleep(random() % MILLION);

        printf("reader %d has left the critical section\n", mynumber);

        sem_wait(&mutex);
        gettimeofday(&v2, 0);

            nreaders--;
            if(nreaders == 0)
                sem_post(&roomEmpty);
        sem_post(&mutex);

    }
    long total = ((v2.tv_sec - v1.tv_sec) + (v2.tv_usec - v1.tv_usec)) / 2;
    printf("reader seconds: %ld\n", total);
    pthread_exit(0);
}


void *threadWriter(void *nothing)
{
    struct timeval v3, v4;
    gettimeofday(&v3, 0);
    int mynumber;

    mynumber = *(int *) nothing;
    
    long writer_time = 0;
    int reps;

    for(reps = 0; reps < 10; reps++){
        usleep(random() % MILLION);

        sem_wait(&roomEmpty);
        gettimeofday(&v4, 0);

        printf("writer %d has entered the critical section\n", mynumber);


        usleep(random() % MILLION);

        sem_post(&roomEmpty);

        printf("writer %d has left the critical section\n", mynumber);

    }
    long total = ((v4.tv_sec - v3.tv_sec) + (v4.tv_usec - v3.tv_usec)) / 2;
    printf("writer seconds: %ld\n", total);
    pthread_exit(0);
}
