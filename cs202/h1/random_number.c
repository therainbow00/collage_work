// problem 14, random number

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    printf("%d\n", rand() % 101);
    return 0;
}
