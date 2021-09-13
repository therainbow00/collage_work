#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define K	1024

/** 2pts
 * Create an array of 1K integers and read in numbers from the standard input
 * and store them in the array until it cannot read anymore numbers, then
 * print out the numbers that were stored in the array in reverse.
 *
 * Example input/output:
 * ./p1 < data
 * 0
 * 1
 * 2
 * 3
 * 4
 * 5
 */

int main(void)
{
    int count = 0;
    //int count = 0;
    char num, integers[K];
    //count = 0;
    while ((scanf(" %c", &num)))
    {
        if (isdigit(num))
        {
            if (count < K)
            {
                integers[count] = num;
                count++;
                integers[count] = '\0';
            }

            //printf("%c\n", num);
        }
        else
        {
            for (int i = 0; integers[i] != '\0'; i++)
            {
                printf("integers[%d]: %c\n", i, integers[i]);
            }
            return 0;
        }
        //int int_num = (int) num;
        /*
        if (isdigit(num))
        {
            if (count < K)
            {
                integers[count] = num;
                count++;
            }
            //printf("%c is a digit", num);
        }
        else
        {
            if (integers[0] == '\0')
            {
                printf("array is empty\n");
            }
            else
            {
                for (int i = 0; integers[i] != '\0'; i++)
                {
                    printf("integers[%d] = %c\n", i, integers[i]);
                }
                return 0;
                //printf("%d is a digit\n", ch);
                //printf("%c is not a digit", num);
            }
        }
        */
    }
    return 0;
}
