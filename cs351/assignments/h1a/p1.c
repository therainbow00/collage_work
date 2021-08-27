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
    printf("Dec\tOct\tHex\n");
    float i;
    int j;
    for (i, j; i < 33, j < 33; i++, j++)
    {
        printf("%2.0f\t%2o\t%2x\n", i, j, j);
    }

  // Main should always have a integer return value.  0 indicates success,
  // non-zero indicates failure of some kind.
  return 0;
}
