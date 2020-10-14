#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int k, result;
    scanf("%d", &k);

    for (int i = 1; i <= k; i++)
    {
        result = (int) pow(i, k);
        printf("%d\n", result);
    }
    return 0;
}
