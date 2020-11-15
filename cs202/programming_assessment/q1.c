/*
Write a C program that sums the squares of the odd numbers from 1 to 37
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n, sum = 0;
    for (int i = 1; i <= 37; i++)
    {
        if (i % 2 == 1)
        {
            //printf("%d\n", i);
            sum += (int) pow(i, 2);
        }
    }
    printf("%d\n", sum);
    return 0;
}
