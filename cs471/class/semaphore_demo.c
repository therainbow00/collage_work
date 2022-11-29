
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NT                 2

pthread_mutex_t *mp;
sem_t s,t;

void *thA(void *nothing);
void *thB(void *nothing);

int main()
{
    pthread_t th[NT];
    int i;

    sem_init(&s, 0, -1);
    sem_init(&t, 0, -1);

    pthread_create(&th[0], 0, (void *) thA, 0);
    pthread_create(&th[1], 0, (void *) thB, 0);

    for(i=0;i<NT;i++)
        pthread_join(th[i], 0);
}

void *thA(void *nothing)
{
    int value;
    sem_getvalue(&s, &value);
    printf("sem s before wait: %d\n", value);
    sem_wait(&s);
    sem_getvalue(&s, &value);
    printf("sem s after wait: %d\n", value);
    printf("B\n");
    sem_getvalue(&t, &value);
    printf("sem t before post: %d\n", value);
    sem_post(&t);
    sem_getvalue(&t, &value);
    printf("sem t after post: %d\n", value);
    sem_getvalue(&s, &value);
    printf("sem s before wait: %d\n", value);
    sem_wait(&s);
    sem_getvalue(&s, &value);
    printf("sem s after wait: %d\n", value);
    printf("D\n");
    pthread_exit(0);
}
void *thB(void *nothing)
{
    int value;
    printf("A\n");
    sem_getvalue(&s, &value);
    printf("sem s before post: %d\n", value);
    sem_post(&s);
    sem_getvalue(&s, &value);
    printf("sem s after post: %d\n", value);
    sem_getvalue(&t, &value);
    printf("sem t before wait: %d\n", value);
    sem_wait(&t);
    sem_getvalue(&t, &value);
    printf("sem t after wait: %d\n", value);
    printf("C\n");
    sem_getvalue(&s, &value);
    printf("sem s before post: %d\n", value);
    sem_post(&s);
    sem_getvalue(&s, &value);
    printf("sem s after post: %d\n", value);
    pthread_exit(0);
}
