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

int main(void)
{
    uint32_t c;
    while ((c = fgetc(stdin)) != EOF)
    {
        if (isdigit(c))
        {
            for (int i = 31; i >= 0; i--)
            {
                if ((c & (1 << i)) != 0)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
            printf("\n");
        }
        else if (isalpha(c))
        {
            return 0;
            printf("\n");
        }
    }
}
