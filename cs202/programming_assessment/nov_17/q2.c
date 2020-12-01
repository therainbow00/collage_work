/*
Read from stdin.  Write the main function for a C program that reads from stdin until EOF and prints the first 5 characters from each line.  Note - you don't need to write the #include's and int main lines.



If the input file were



Hello there.  My name is Jeff.

And how are you?

And who are you?



then the output would be



Hello

And h

And w
*/

#include <stdio.h>

int main()
{
    char c;
    int count = 1;
    while ((c = fgetc(stdin)) != EOF)
    {
        if (count <= 5)
        {
            printf("%c", c);
            count++;
        }
        else if (c == '\n')
        {
            count = 0;
        }
    }
    return 0;
}
