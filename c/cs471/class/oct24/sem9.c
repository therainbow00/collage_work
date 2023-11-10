
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
sem_t mutex;               // protect nreaders variable
sem_t roomEmpty;           // blocks when thread(s) are in critical section(s)
sem_t turnstile;           // allows arriving writers to enter critical section before readers that arrive later

void *threadReader(void *nothing);  // function for the reader thread
void *threadWriter(void *nothing);  // function for the writer thread

int main(int argc, char *argv[])
{
    pthread_t th[NTHREADS];            // pthread's thread data structure
    int numbers[NTHREADS];             // array with thread id's
    double x,y;

    sem_init(&turnstile, 0, 1);        // 
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
    
    return 0;
}

void *threadReader(void *nothing)
{
    struct timeval v1, v2;
    gettimeofday(&v1, 0);
    int mynumber;

    mynumber = *(int *) nothing;

    for(int reps = 0; reps < 2; reps++){
        usleep(random() % MILLION);  // simulate doing non-critical work

        sem_wait(&turnstile);
        gettimeofday(&v2, 0);
        sem_post(&turnstile);

        sem_wait(&mutex);
            nreaders++;
            if(nreaders == 1)
                sem_wait(&roomEmpty);
                gettimeofday(&v2, 0);
        gettimeofday(&v2, 0);
        sem_post(&mutex);

        printf("reader %d has entered the critical section\n", mynumber);

// beginning of critical section

        usleep(random() % MILLION);  // simulate time to do work in critical section

// end of critical section

        printf("reader %d has left the critical section\n", mynumber);

        sem_wait(&mutex);
            nreaders--;
            if(nreaders == 0)
                sem_post(&roomEmpty);
        gettimeofday(&v2, 0);
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

    for(int reps = 0; reps < 2; reps++){
        usleep(random() % MILLION);   // simulate doing non-critical work

        sem_wait(&turnstile);
        gettimeofday(&v4, 0);
            sem_wait(&roomEmpty);
            gettimeofday(&v4, 0);
        sem_post(&turnstile);
        
            printf("writer %d has entered the critical section\n", mynumber);

// beginning of writer's critical section

            usleep(random() % MILLION);   // simulate doing work

// end of writer's critical section

        sem_post(&roomEmpty);

        printf("writer %d has left the critical section\n", mynumber);

    }
    long total = ((v4.tv_sec - v3.tv_sec) + (v4.tv_usec - v3.tv_usec)) / 2;
    printf("writer seconds: %ld\n", total);
    pthread_exit(0);
}
