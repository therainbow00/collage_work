
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define TRUE      1
#define FALSE     0

#define NBOATS   10
#define NPASS    40

sem_t boatflag_mutex;  // protects boatflag (which indicates whether a boat is docked)
sem_t pass_mutex;      // protects npassengers (which counts the number of passengers on board)
sem_t dock_mutex;      // protects access to the dock (only one boat at a time can dock)

int npassengers, boatflag;

void dock();
void sail();
void *Boat(void *nothing);
void arrive(int n);
void board(int n);
void *Passenger(void *nothing);

int main(int argc, char *argv[])
{
    pthread_t boat_th[NBOATS];   // boat threads
    pthread_t pass_th[NPASS ];   // passenger threads
    int id[NPASS];

    sem_init(&boatflag_mutex,0,1);
    sem_init(&pass_mutex,0,1);
    sem_init(&dock_mutex,0,1);

    npassengers = 0;
    boatflag = FALSE;

    for(int i=0;i<NPASS;i++)
        id[i] = i+1;           // passengers numbered from 1

// create all the threads

    for(int i=0;i<NPASS;i++)
        pthread_create(&pass_th[i], 0, (void *) Passenger, &id[i]); 
    for(int i=0;i<NBOATS;i++)
        pthread_create(&boat_th[i], 0, (void *) Boat, 0); 

// wait for all threads to complete

    for(int i=0;i<NPASS;i++)
        pthread_join(pass_th[i], 0);
    for(int i=0;i<NBOATS;i++)
        pthread_join(boat_th[i], 0);

    return 0;
}
void dock()             // run by Boat when it docks
{
    printf("A boat docks.\n");
    sem_wait(&pass_mutex);
        npassengers = 0;                  // initialize passenger count
    sem_post(&pass_mutex);
    sem_wait(&boatflag_mutex);
        boatflag = TRUE;                  // indicates there is now a boat at the dock
    sem_post(&boatflag_mutex);
}
void sail()
{
    sem_wait(&pass_mutex);
        printf("A boat sails with %d passengers.\n", npassengers);
    sem_post(&pass_mutex);
    sem_wait(&boatflag_mutex);
        boatflag = FALSE;
    sem_post(&boatflag_mutex);
}
void *Boat(void *nothing)
{
    int ncopy;

    sem_wait(&dock_mutex);
        dock();
        for(;;){
            sem_wait(&pass_mutex);
            if(npassengers == 4)
                break;
            else
                sem_post(&pass_mutex);
        }
        sem_post(&pass_mutex);
        sail();
    sem_post(&dock_mutex);
    pthread_exit(0);
}
void arrive(int n)
{
    printf("Passenger %d has arrived.\n", n);
}
void board(int n)   // passenger running this holds both mutexs
{
    npassengers++;
    printf("Passenger %d has boarded in position %d.\n", n, npassengers);
}
void *Passenger(void *nothing)
{
    int id;           //  id number for this passenger
    int boarded;      // local flag to indicate whether this passenger has boarded

    id = * (int *) nothing;         // get the passenger ID
    arrive(id);                     // run the arrive function (does nothing)
    boarded = FALSE;                // 
    while(!boarded){                // ! is NOT in C/Java/Javascript, etc.
        sem_wait(&boatflag_mutex);
            if (boatflag)
            {                       // wait for access to the boatflag
                sem_wait(&pass_mutex);  // and the npassengers variable
                if(npassengers < 4){  // don't board unless there's an empty seat
                    board(id);
                    boarded = TRUE;   // this passenger has boarder
                }
            }
            sem_post(&pass_mutex);
        sem_post(&boatflag_mutex);
    }
    pthread_exit(0);
}
