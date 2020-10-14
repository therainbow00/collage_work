// problem 19, factors

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i;
    printf("Interger please: ");
    scanf("%d", &n);

    i = 1;
    while (i <= n)
    {
        if (n % i == 0)
        {
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}
