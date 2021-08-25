#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** 1pt
 * Create a program that:
 *  - Functions are described in C lesson 4
 *  - Completes the bittest() function that returns non-zero (i.e. true) if
 *    bit i in num is set and returns 0 if it is not.
 *  - Complete main:
 *    - To read a decimal number into a 32 bit integer
 *    - Count the number of set bits in the number read using a loop and the
 *      bittest function.  Each time a set bit is encountered, increment a
 *      counter variable (make sure it is initialized to zero before counting.)
 *    - At the end print the number as a zero-padded 8 digit uppercase hex value
 *      followed by the count of set bits in the number.
 */

int bittest(uint32_t num, int i)
{
    int _true = 1;
    int _false = 0;
    if ((num & (1 << i)) != 0)
    {
        return _true;
    }
    else
    {
        return _false;
    }
}

int main(int argc, char *argv[])
{
    float decimal;
    printf("Input a decimal number: ");
    scanf("%f", &decimal);
    uint32_t decimal_int = (uint32_t) decimal;
    int count = 0;

    for (int i = 31; i >= 0; i--)
    {
        if (bittest(decimal, i) != 0)
        {
            count++;
        }
    }
    printf("%08X: %d\n", decimal_int, count);
    return 0;
}
