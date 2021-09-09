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
    int k, count, i, m;

    printf("    ");
    for (i = 2; i <= 7; i++) printf("%x ", i);
    printf("\n");
    printf("  -------------");
    printf("\n");

    for (m = 0; m <= 15; m++)
    {

        count = 0;
        k = 32 + m;

        printf("%2X: ", m);

        for (k; k <= 127; k += 16)
        {
            if (count == 6)
            {
                printf("\n");
                break;
            }
            else
            {
                if (k == 127)
                {
                    printf("DEL");
                    count++;
                }
                else
                {
                    printf("%c ", k);
                    count++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
