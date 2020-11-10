#include <stdio.h>
#include <math.h>

int main()
{
    int n, sum = 0;
    for (int i = 1; i <= 37; i++)
    {
        if (i % 2 == 1)
        {
            //printf("%d\n", i);
            sum += (int) pow(i, 2);
        }
    }
    printf("%d\n", sum);
    return 0;
}
