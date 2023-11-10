// problem 9, add up

#include <stdio.h>

int main()
{
    int total = 0;
    int i;

    for (i = 1; i < 11; i++)
    {
        total = total + i;
    }
    printf("%d\n", total);
    return 0;
}
