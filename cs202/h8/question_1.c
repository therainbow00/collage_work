/*
**************************************************************************
Question 1 - What is the difference between the following?
             S1 = sum of 1! +   2! +   3! + ... +   12!
             S2 = sum of 2**1 + 2**2 + 2**3 + ... + 2**12
What is the value of S1 - S2?

Note - this is small enough that you can also check this by hand or typing into google.  You also need to have a C program to verify your answer.

Note - there was a mistake in my program earlier.  The answer is not what we had on the screen in class.  That has been correct now, so definitely put in the correct answer for this question.
*/
#include <stdio.h>
#include <math.h>

int main()
{
    int s1 = 0, s2 = 0, total = 1, k = 1, i, num, result;

    printf("Enter interger (must be greater than 0): ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        total *= i;
        s1 += total;
    }

    while (k <= 12)
    {
        result = (int) pow(2, k);
        s2 += result;
        k++;
    }
    printf("sum of s1: %d\n", s1);
    printf("sum of s2: %d\n", s2);
    printf("s1 - s2 = %d\n", s1 - s2);
}
