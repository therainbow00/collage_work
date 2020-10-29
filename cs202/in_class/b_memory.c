#include <stdio.h>
#include <stdlib.h>

unsigned long int pointer_difference(void *p1, void *p2)
{
    return p1 - p2;
}

int global1, global2;

int main(int argc, char *argv[])
{
    int local1, local2;

    int * dynamic1 = (int *)malloc(sizeof(int));
    int * dynamic2 = (int *)malloc(sizeof(int));

    printf("Global variable addresses...\n"
           "%p &global1\n%p &global2\n%ld\n\n", &global1, &global2)
}
