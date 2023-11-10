
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <pthread.h>
#include <semaphore.h>

#define NTHREADS  7
#define K         3

int count;
sem_t mutex;

void *the_thread(void *nothing);

int main(int argc, char *argv[])
{
    pthread_t th[NTHREADS];

    srandom(getpid());

    int count = 0;
    sem_init(&mutex, 0, 1);

    for(int i = 0 ; i < NTHREADS ; i++)
        pthread_create(&th[i], 0, (void *) the_thread, 0);

    for(int i = 0 ; i < NTHREADS ; i++)
        pthread_join(th[i], 0);
    
    return 0;
}

void *the_thread(void *nothing)
{
    int flag;
    usleep(random() % 1000000);     // simulate doing job 1

    sem_wait(&mutex);
    count += 1;
    if (count <= K) flag = 1;
    else flag = 0;
    sem_post(&mutex);

    if (flag) printf("only %d of the %d threads should print this\n", K, NTHREADS);

    usleep(random() % 1000000);   // simulate doing job 3
    pthread_exit(0);
}
