#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j, k, num;
    char a, b;
    scanf("%d", &num);
    //printf("1\n");
    //printf("(1)\n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j <= i; j++)
        {
            putchar('a');
        }

        for (k = 0; k < j; k++)
        {
            putchar('b');
            //printf("\n(j): %d, (i): %d", j, i);
        }
    }
    printf("\n");
    return 0;
}
