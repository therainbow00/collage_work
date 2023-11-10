#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NTHREADS                 2

pthread_mutex_t *mp;
sem_t d, p;

void *boat(void *nothing);
void *pass(void *nothing);

int main()
{
    pthread_t threads[NTHREADS];
    int i;

    sem_init(&d, 0, 0);
    sem_init(&p, 0, 0);

    pthread_create(&threads[0], 0, (void *) boat, 0);
    pthread_create(&threads[1], 0, (void *) pass, 0);

    for(i = 0; i < NTHREADS; i++) pthread_join(threads[i], 0);

    return 0;
}

void dock(sem_t *sem)
{
    int value;
    sem_getvalue(sem, &value);
    if (value > 0)
    {
        sem_wait(sem);
        printf("dock is empty\n");
    }
    else if (value == 0 || value < 0)
    {
        printf("dock is busy\n");
        sem_post(sem);
    }
    sem_getvalue(sem, &value);
    printf("sem d: %d\n", value);
}

void sail(sem_t *sem)
{
    printf("leaving dock with passengers\n");
    sem_post(sem);
}

void arrive()
{
    printf("passengers have arrived and are waiting\n");
}

void board(int passen, sem_t *sem)
{
    printf("passenger %d has boarded\n", passen);
    sail(sem);
}

void *pass(void *nothing)
{
    for (int num_pass = 0; num_pass < 4; num_pass++)
    {
        arrive();
        board(num_pass, &p);
        pthread_exit(0);
    }
}

void *boat(void *nothing)
{
    dock(&d);
    sail(&p);
    pthread_exit(0);
}
