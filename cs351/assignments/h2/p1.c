#include <stdio.h>

/** 2pts
 * Complete the program to output an ASCII chart similar to the one found in
 * 'man ascii'.  The top and side numbers are in hexadecimal.  The top number
 * represents the upper 4 bit value of the character and the side number the
 * lower 4 bits of the character.
 */

int main(void)
{
    /*
    char character, num;
    printf("   ");
    for (num = 2; num <= 7; num++)
    {
        printf(" %x", num);
    }
    printf("\n");
    printf("  -------------");
    printf("\n");
    for (character = 0; character <= 15; character++)
    {
        printf(" %X: %c", character, character);
        printf("\n");
    }
    */
    int i = 0;
    char ch;

    for (i = 0; i < 256; i++)
    {
      printf("%c ", ch);
      ch = ch + 1;
    }
    return 0;
}
