#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** 1pt
 * Complete the following program:
 *  - Input two 32 bit decimal numbers a and b
 *  - Print out both a and b as 32 bit binary values
 *  - Print out as a 32 bit binary value a 1 where there is both a 1 in a and b
 *    at that bit position and a 0 if they are not the same or are both 0 at
 *    that bit position.
 */
int main(void)
{
    printf("Input a: ");
    float a, b;
    //349587, 34598745
    scanf("%f", &a);

    printf("Input b: ");
    scanf("%f", &b);

    unsigned int a_uint = (unsigned int) a;
    unsigned int b_uint = (unsigned int) b;

    //printing a in binary
    printf("a = ");
    for (int i = 31; i >= 0; i--)
    {
        if ((a_uint & (1 << i)) != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");

    //printing b in binary
    printf("b = ");
    for (int j = 31; j >= 0; j--)
    {
        if ((b_uint & (1 << j)) != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");

    //printing c in binary
    printf("c = ");
    for (int k = 31; k >= 0; k--)
    {
        if ((a_uint & (1 << k)) && (b_uint & (1 << k)) != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}
