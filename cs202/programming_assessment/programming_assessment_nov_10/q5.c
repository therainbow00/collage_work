/*
Bits.  Write a C function named hexDigitAdd that has an unsigned int as parameter and returns an int.  The function should add up the digits of the number when viewed as a hexadecimal number and return the sum.  If the number in hex were 0x1234, then the return value would be 10.  If the number in hex were 0xf04, then the return value would be 19.
*/
#include <stdio.h>

int main()
{
    int sum = 0, num = 20;
    for (int i = 0; i < num; i++)
    {
        int hex = num % 16;
        printf("%d in hex = %x\n", i, i);
    }

    return 0;
}
