/*
Write a C program that reads a file from stdin one character at a time and counts the number of times the
lower case letter x appears
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char c;
    int count, c1;

    FILE *f;
    f = fopen(argv[1], "r");
    while ((c1 = fgetc(f)) != EOF)
    {
        if (c1 == 'x')
        {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
