// problem 20, is prime

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("Interger: ");
    int x, i, flag = 0;
    scanf("%d", &x);
    if (x < 1 )
    {
        printf("enter positive numbers only.\n");
        exit(0);
    }

    for (i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            flag = 1;
            break;
        }
    }

    if (x == 1)
    {
        printf("not prime\n");
    }
    else if (flag == 0)
    {
        printf("prime\n");
    }
    else
    {
        printf("not prime\n");
    }
    return 0;
}
