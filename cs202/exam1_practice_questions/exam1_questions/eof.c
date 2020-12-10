/*
Give C code to do the following.

Read from stdin until EOF, print each character, keep track of the number of \n characters read and after each \n character print the count (so that you will have the line numbers printed).  Start counting the # of lines at 1, and print out "1: " before your while loop.
*/
#include <stdio.h>

int main()
{
    int a, count = 1;
    while ((a = fgetc(stdin)) != EOF)
    {
        printf("%4d: ", count);
        if (a == '\n')
        {
            count++;
            //printf("%d: ", count);
        }
        else if (a != '\n')
        {
            printf("%c", a);
        }
    }
    return 0;
}
