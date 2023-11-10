#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define K	1024

/** 3pts
 * Complete the functions below to make a program that reads one line of input
 * and prints a count of each letter read.
 */

// Returns ch as a lower-case letter if it is uppercase.  Everything else is
// returned as-is:
int lower(int ch)
{
    if (isupper(ch))
    {
        return tolower(ch);
    }
    else
    {
        return ch;
    }
}

// Returns true if 'ch' is a letter (a-z, A-Z), false otherwise:
int isletter(int ch)
{
    int true = 1, false = 0;
    if (isalpha(ch))
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
    printf("Input: ");
    char s[K];
    fgets(s, K, stdin);

    int count = 0;
    for (int j = 'a'; j <= 'z'; j++)
    {
        count = 0;
        printf("%c: ", j);
        for (int i = 0; s[i] != '\n'; i++)
        {
            if (isletter(s[i]))
            {
                if ((lower(s[i])) == j) count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
