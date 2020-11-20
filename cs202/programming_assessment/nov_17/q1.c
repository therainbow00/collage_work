/*
Loops question.  Write a C program that reads an integer k from the user and then prints the multiples of 1 up to k, the multiples of 2 up to k/2, etc.  Note - write the complete program, including #include's, etc.



For k=10, the printout would be -



1, 2, 3, 4, 5, 6, 7, 8, 9, 10,

2, 4, 6, 8, 10,

3, 6, 9,

4, 8,

5, 10,
*/

#include <stdio.h>

int main()
{
    int k, x = 1;
    printf("Interger please: ");
    scanf("%d", &k);
    /*
    while (x <= k)
    {

    }
    */
    for (int i = 1; i <= k; i++)
    {
        printf("%d, ", i);
    }
    printf("\n");
    for (int j = 1; j <= k; j++)
    {
        if ((j * 2) > k)
        {
            break;
        }
        else
        {
            printf("%d, ", j * 2);
        }
    }
    printf("\n");
    for (int l = 1; l < k; l++)
    {
        if ((l * 3) > k)
        {
            break;
        }
        else
        {
            printf("%d, ", l * 3);
        }
    }
    printf("\n");
    for (int a = 1; a < k; a++)
    {
        if ((a * 4) > k)
        {
            break;
        }
        else
        {
            printf("%d, ", a * 4);
        }
    }
    printf("\n");
    for (int b = 1; b < k; b++)
    {
        if ((b * 5) > k)
        {
            break;
        }
        else
        {
            printf("%d, ", b * 5);
        }
    }
    printf("\n");

    /*
    for (int i = 1; i <= k; i++)
    {
        printf("%d, ", i);
        if (i % 2 == 0)
        {
            printf("\n");
            printf("%d, ", i);
        }
        if ((i * 3) < k)
        {
            printf("\n");
            printf("%d, ", i * 3);
        }
        if ((i * 4) < k)
        {
            printf("\n");
            printf("%d, ", i * 4);
        }
        if ((i * 5) < k)
        {
            printf("\n");
            printf("%d, ", i * 5);
        }
    }
    printf("\n");
    */
    return 0;
}
