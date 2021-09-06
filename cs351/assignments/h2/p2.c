#include <stdio.h>
#include <string.h>

#define K	1024

/**  1pt
 * Read a line of input and then for each character in the string output the
 * original character if the index position of the character is divisible by
 * 3, otherwise print a space character instead.  The newline can be printed
 * as-is.
 */

int main(void)
{
    char s[K];
    printf("Input: ");
    fgets(s, K, stdin);

    for (int i = 0; s[i] != '\n'; i++)
    {
        if (i % 3 == 0) printf("%c", s[i]);
        else printf(" ");
    }
    printf("\n");
}
