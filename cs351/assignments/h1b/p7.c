#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** 2pts
 * Create a program to get a 32 bit unsigned integer from the user and negate it
 * using only binary operations and increments (you can also use the addition of
 * +1). Display both the original number and the negated number in binary
 * followed by the decimal value.  Print the numbers as though they were signed.
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
 }

int main(void)
{
    uint32_t num;
    printf("Input number: ");
    scanf("%u", &num);

    printf("%u\n", num);
    printbinary(num);
    printf("\n");

    num = ~num + 1;

    printbinary(num);
    printf("\n");
    return 0;
}
