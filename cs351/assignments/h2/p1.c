#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** 2pts
 * Complete the program to output an ASCII chart similar to the one found in
 * 'man ascii'.  The top and side numbers are in hexadecimal.  The top number
 * represents the upper 4 bit value of the character and the side number the
 * lower 4 bits of the character.
 */

int bittest(uint8_t num, int i)
{
    int _false = 0, _true = 1;
    if ((num & (1 << i)))
    {
        return _true;
    }
    else
    {
        return _false;
    }

}

int printbinary(uint8_t num)
{
    for (int i = 7; i >= 0; i--)
    {
        return bittest(num, i);
    }
}

int main(void)
{
    int k;
    uint16_t i, j, sum = 0;

    printf("   ");
    for (i = 0; i <= 15; i++)
    {
        for (j = 2; j <= 7; j++)
        {
            if (i == 0)
            {
                printf("%X ", j);
            }
            sum = 0;
            for (k = 15; k >= 0; k--)
            {
                sum += ((i & (1 << k)) | (j & (1 << k)));
                //printf("%u\n", sum);
            }
            //printf("%u\n", sum);
        }
        if (i == 0)
        {
            printf("\n");
            printf("---------------");
        }
        printf("\n");
        printf("%d\n", sum);
        //printf("%X: %c\n", i, count);
        //count++;
    }

    /*
    for (k = 32; k <= 127; k++)
    {
        printf("%X: %c\n", k, k);
    }
    0000000000000010 0000000000000000 =

    */
    return 0;
}
