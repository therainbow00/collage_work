/*
Read from stdin.  Write the main function for a C program that reads from stdin until EOF and prints the characters but replacing \t characters with "    " (four spaces).  Note - you don't need to write the #include's and int main lines.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char c;
    while ((c = fgetc(stdin)) != EOF)
    {
        if (c == '\t')
        {
            printf("    ");
        }
        else
        {
            printf("%c", c);
        }
    }
    return 0;
}
