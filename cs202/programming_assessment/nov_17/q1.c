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
    int k, i, j;
    printf("Interger please: ");
    scanf("%d", &k);

    for (i = 1; i <= k; i++)
    {
        for (j = 1; j <= k; j++)
        {
            if ((i * j) > k)
            {
                break;
            }
            else
            {
                printf("%d, ", i * j);
            }
        }
        printf("\n");
    }
    return 0;
}
