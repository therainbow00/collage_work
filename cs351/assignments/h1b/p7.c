#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** 2pts
 * Create a program to get a 32 bit unsigned integer from the user and negate it
 * using only binary operations and increments (you can also use the addition of
 * +1). Display both the original number and the negated number in binary
 * followed by the decimal value.  Print the numbers as though they were signed.
 */

int main(void)
{
    uint32_t num;
    printf("Input number: ");
    scanf("%u", &num);
    int i, j, k;

    for (i = 31; i >= 0; i--)
    {
        if ((num & (1 << i)) != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf(" %u", num);
    printf("\n");

    for (j = 31; j >= 0; j--)
    {
        if ((num & (1 << j)) != 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
    }
    //printf(" %d", ~num);
    printf("\n");


    for (k = 30; k >= 0; k--)
    {
        if ((num & (1 << k)) && (num & (1 << j))
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
    }
    printf("\n");

    return 0;
}
