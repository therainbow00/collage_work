#include <stdio.h>

void staircase(int n) {
    if (n > 0 && n <= 100)
    {
        int i, j, k;
        for (i = 0; i < n; i++)
        {

            for (j = i; j < (n - 1); j++)
            {
                printf(" ");
            }


            for (k = 0; k <= i; k++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    staircase(n);
    return 0;
}
