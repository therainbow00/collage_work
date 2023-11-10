#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define K	1024

/** 2pts
 * Read a line of input and for each character in the string, if the character
 * is a vowel (upper or lowercase) print it as-is, otherwise print a space
 * instead.  You may also print the newline as-is.  You may use the ctype
 * and string functions for this problem.
 */

// Returns true if 'ch' holds a vowel (a,e,i,o or u), false otherwise.
int isvowel(char ch)
{
    int true = 1, false = 0;
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        return true;
    }
    else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    char s[K];
    printf("Input: ");
    fgets(s, K, stdin);

    for (int i = 0; s[i] != '\n'; i++)
    {
        if (isvowel(s[i]) == 1) printf("%c", s[i]);
        else printf(" ");
    }
    printf("\n");
    return 0;
}
