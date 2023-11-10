
typedef struct barrier {
    sem_t mutex;   // to protect counter
    sem_t turnstile1, turnstile2;
    int count;
    int target;    // this is 3 in the H2O example
} BARRIER;

BARRIER *init_barrier(int target);
void wait_barrier(BARRIER *barr, char *who);   // who is for debugging

