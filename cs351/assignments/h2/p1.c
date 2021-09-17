#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** 2pts
 * Complete the program to output an ASCII chart similar to the one found in
 * 'man ascii'.  The top and side numbers are in hexadecimal.  The top number
 * represents the upper 4 bit value of the character and the side number the
 * lower 4 bits of the character.
 */

int main(void)
{
    uint16_t i, j;

    printf("    ");
    for (i = 2; i <= 7; i++) printf("%x ", i);
    printf("\n");
    printf("  -------------");
    printf("\n");

    for (i = 0; i <= 15; i++)
    {
        printf("%2X: ", i);
        for (j = 2; j <= 7; j++)
        {
            if (j * 16 + i == 127) printf("DEL");
            else printf("%c ", j << 4 | i);

            //int c = h << 4 | l;

        }
        printf("\n");
    }
    return 0;
}
