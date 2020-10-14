// problem 18, factorials

#include <stdio.h>

int main(int argc, char *argv[])
{
    int total = 1, i, num;
    printf("Enter interger (must be greater than 0): ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        total *= i;
        printf("%d! = %d\n", i, total);
    }
    return 0;

}
