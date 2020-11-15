/*
Loops question.  Write a C program that reads an integer k from the user and then prints a figure like the following (shown for k=4).  Note - write the complete program, including #include's, etc.



abcd
bbcd
cccd
dddd
*/

#include <stdio.h>

int main()
{
    int k, i = 0;
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    printf("Interger please: ");
    scanf("%d", &k);

    while (i != (k + 1))
    {
        if (i < k)
        {
            printf("%c", letters[i]);
        }
        i++;
    }
    printf("\n");
    i = 0;
    while (i != (k + 1))
    {
        if (i < k)
        {
            printf("%c", letters[1]);
        }
        i++;
    }
    printf("\n");
    i = 0;
    while (i != k)
    {
        if (i < (k - 2))
        {
            printf("%c", letters[1]);
        }
        else if (i >= (k - 2))
        {
            printf("%c", letters[i]);
        }
        i++;
    }
    printf("\n");
    return 0;
}
