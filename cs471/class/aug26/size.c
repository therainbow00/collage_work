#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define X 1000000
int main(int argc, char *argv[])
{
    int *p;
    printf("start\n");
    getchar();
    p = malloc(X*sizeof(int));
    printf("after malloc\n");
    return 0;
}
