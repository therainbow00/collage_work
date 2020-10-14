#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j, num, k;
    char a, b, result;
    scanf("%d", &num);
    //printf("1\n");
    //printf("(1)\n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < i; j++)
        {
            putchar('a');
        }

        for (j = i; j <= num; j++)
        {
            putchar('b');
            //printf("\n(j): %d, (i): %d", j, i);
        }
    }
    printf("\n");
    return 0;
}
