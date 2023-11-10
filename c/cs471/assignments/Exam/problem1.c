
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define TWOMILLION  2000000

sem_t mutex;    // a mutex might be useful for this problem

int x;          // the first number
int y;          // the second number
int sum;        // the sum of x and y
int count;      // another variable (might be useful)

void *threadX(void *nothing);
void *threadY(void *nothing);
void *threadSum(void *nothing);

int main(int argc, char *argv[])
{
    pthread_t th[3];

    srandom(getpid());        // seed the random number generator differently each time

    sem_init(&mutex, 0, 1);   // the mutex initialized to 1
    count = 0;                // counts how many numbers have been obtained

// create the threads

    pthread_create(&th[0], 0, (void *) threadX, 0);
    pthread_create(&th[1], 0, (void *) threadY, 0);
    pthread_create(&th[2], 0, (void *) threadSum, 0);

// wait for all threads to finish

    pthread_join(th[0], 0);
    pthread_join(th[1], 0);
    pthread_join(th[2], 0);

// print the sum

    printf("%d + %d = %d\n", x, y, sum);

    return 0;
}
int getnumber()
{
    usleep(random() % TWOMILLION);  // simulates work that must be done to get the data
    return 1000 + random() % 1000;
}
void *threadX(void *nothing)
{
    sem_wait(&mutex);
        x = getnumber();    // x is global
        count++;
    sem_post(&mutex);
    sum += x;
    pthread_exit(0);
}
void *threadY(void *nothing)
{
    sem_wait(&mutex);
        y = getnumber();    // y is global
        count++;
    sem_post(&mutex);
    sum += y;
    pthread_exit(0);
}
void *threadSum(void *nothing)
{
    sem_wait(&mutex);
    sum = x + y;
    sem_post(&mutex);
    pthread_exit(0);
}
