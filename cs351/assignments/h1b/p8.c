#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

/** 2pts
 * Create a program that reads numbers from the input (it should print no
 * prompts,) until it fails to read a number.  For each number read it should
 * print them as "binary" substituting # for 1 and a space for 0 instead.
 * The test data file can be read into the program using the < operator on the
 * command line, i.e.:
 * ./p8 < data
 */

 int bittest(uint32_t num, int i)
 {
     int _false = 0, _true = 1;
     if (num & (1 << i)) return _true;
     else return _false;
 }

 void printbinary(uint32_t num)
 {
     for (int i = 31; i >= 0; i--)
     {
         if (bittest(num, i)) printf("#");
         else printf(" ");
     }
 }

int main(void)
{
    uint32_t c;
    while ((scanf("%u", &c)) == 1)
    {
        printbinary(c);
        printf("\n");
    }
}
