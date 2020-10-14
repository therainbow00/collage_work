// problem 12, addition facts

#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = i; j <= 9; j++)
        {
            int a, b, result;
            a = i;
            b = j;
            result = a + b;
            printf("%d + %d = %d\n", a, b, result);
        }
    }
    return 0;
}
