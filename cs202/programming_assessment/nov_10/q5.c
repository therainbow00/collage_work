/*
Bits.  Write a C function named hexDigitAdd that has an unsigned int as parameter and returns an int.  The function should add up the digits of the number when viewed as a hexadecimal number and return the sum.  If the number in hex were 0x1234, then the return value would be 10.  If the number in hex were 0xf04, then the return value would be 19.
*/
#include <stdio.h>

int hexDigitAdd(unsigned int num)
{
    int sum = 0, arr[51];
    printf("%x, %d", num, num);
    /*
    for (int j = 0; j < sizeof(arr); j++)
    {
        arr[j] = num;
        printf("%d\n", arr[j]);
    }
    */
    /*
    for (unsigned int i = 0; i < num; i++)
    {
        unsigned int hex = num % 16;
        printf("%d in hex = %x\n", hex, hex);
        printf("%d\n", i);
    }
    return sum;
    */
}

int main()
{
    unsigned int num, total;
    printf("Hex number please: ");
    scanf("%x", &num);
    //unsigned int hex = num % 16;
    //printf("%d\n", hex);

    total = hexDigitAdd(num);
    printf("%d\n", total);

    return 0;
}
