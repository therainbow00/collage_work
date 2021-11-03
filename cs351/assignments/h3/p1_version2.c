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
    int num, integers[K], count = 0, count1 = 0;
    while ((scanf("%d", &num)) == 1)
    {
        if (count < K)
        {
            integers[count] = num;
            count++;
        }
        integers[count] = '\0';
    }
    if (count)
    {
        for (int i = count - 1; i >= 0; i--)
        {
            if (integers[i] == 0)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", integers[i]);
            }
            count1++;
        }
        return 0;
    }
    else
    {
        return 0;
    }
}
