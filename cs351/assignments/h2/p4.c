#include <stdio.h>
#include <string.h>

#define K	1024

/** 2pts
 * Complete the functions to read a line of text input and print each character
 * read as it's original ASCII representation followed by it's binary value
 * and finally it's decimal value.
 */

void printbinary(char ch)
{
    for (int i = 7; i >= 0; i--)
    {
        if ((ch & (1 << i))) printf("1");
        else printf("0");
    }
}

int main(void)
{
    printf("Input: ");
    char s[K];
    fgets(s, K, stdin);

    for (int i = 0; s[i] != '\n'; i++)
    {
        printf("%c: ", s[i]);
        printbinary(s[i]);
        printf("  %d", s[i]);
        printf("\n");
    }
    return 0;
}
