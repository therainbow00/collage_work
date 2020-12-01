/*
Bits.  Write a C function named truncateBytes that has an unsigned int as parameter and returns an unsigned int.  The function should "truncate" off the last 3 bytes of the integer, returning the integer that is made of the first byte of the integer with the last 3 bytes being 0's.  If the number in hex were 0xff87ab12, then the return value in hex would be 0xff000000.  Note that the number is an unsigned int and so is the return type.
*/

#include <stdio.h>

unsigned int trucatBytes(unsigned int num)
{
    return num >> 24;
}

int main()
{
    unsigned int number;
    printf("Interger please: ");
    scanf("%d", &number);

    unsigned int x = trucatBytes(number);
    printf("number: %#u\n", x);
    //printf("number in hex: %#x\n", number);
    return 0;
}
