// problem 13, math facts

#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, addition_result, multiply_result, subtraction_result, division_result;

    for (int i = 1; i <= 9; i++)
    {
        for (int j = i; j <= 9; j++)
        {
            a = i;
            b = j;
            multiply_result = a * b;
            printf("%d * %d = %d\n", a, b, multiply_result);
        }
    }
    printf("\n");

    for (int i = 1; i <= 9; i++)
    {
        for (int j = i; j <= 9; j++)
        {
            a = i;
            b = j;
            subtraction_result = a - b;
            printf("%d - %d = %d\n", a, b, subtraction_result);
        }
    }
    printf("\n");

    for (int i = 1; i <= 9; i++)
    {
        for (int j = i; j <= 9; j++)
        {
            a = i;
            b = j;
            division_result = a % b;
            printf("%d / %d = %d\n", a, b, division_result);
        }
    }
    return 0;
}
