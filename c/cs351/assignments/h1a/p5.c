#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** 1pt
 * Complete the following program:
 *  - Complete bittest in the same manner as h4.c
 *  - Complete printbinary that uses bittest and a loop similar to the one used in
 *    h3.c to print the value given by 'num' in binary (printbinary should _not_
 *    print a newline at the end however.
 *  - Complete main to print:
 *    - print for i ranging from 0 to 31 the binary value for a 1 shifted to
 *      position i, to be displayed in both binary and then decimal.
 *      Prefix the values with the bit position.
 */

int bittest(uint32_t num, int i)
{
    int _false = 0, _true = 1;
    if ((num & (1 << i)) != 0)
    {
        return _true;
    }
    else
    {
        return _false;
    }

}

void printbinary(uint32_t num)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", bittest(num, i));
    }
    printf(" %u", num);
}

int main(void)
{
    for (int i = 0; i <= 31; i++)
    {
        printf("%2d: ", i);
        printbinary(1 << i);
        printf("\n");
    }
    return 0;
}
