// Write a C program that reads from stdin until EOF and prints everything but replaces all tab characters ('\t') with two spaces.  Note that this means you need to check if a characters is  '\t' and if it is print "  " instead of '\t'

#include <stdio.h>

int main()
{
    int n;
    while ((n = fgetc(stdin)) != EOF)
    {
        if (n == '\t')
        {
            printf("  ");
        }
        else
        {
            printf("%c", n);
        }
    }
    return 0;
}
