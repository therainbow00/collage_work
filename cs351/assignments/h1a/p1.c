#include <stdio.h>

/** 1pt
 * Complete the main function to:
 *  - Make a loop to print the values 0 through 32 (inclusive) in decimal, octal
 *    and hexadecimal.  The output of each number is right aligned to 2 columns.
 * Look at C lesson 3 for information on how to make a while or for-loop
 * Look at C lesson 1 for information on how to output numbers using printf
 */

int main(void)
{
    for (float i; i < 33.0; i++)
    {
        printf("%5.2f\n", i);
    }

    printf("---\n");

    for (int i; i < 33; i++)
    {
        printf("%5o\n", i);
    }

    printf("---\n");

    for (int i; i < 33; i++)
    {
        printf("%5x\n", i);
    }

  // Main should always have a integer return value.  0 indicates success,
  // non-zero indicates failure of some kind.
  return 0;
}
