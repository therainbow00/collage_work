#include <stdio.h>

int main(void)
{
    int i;

    /*
     * print the values 0 through 10 inclusive:
    */

    // while loop method:
    i = 0;
    while (i <= 10)
    {
        printf("%d\n", i);
        i = i + 1;
    }

    printf("---\n");

    //for loop method:
    for (i = 0; i <= 10; i++)
    {
        printf("%d\n", i);
    }

    //for loop method:
    for (i = 10; i >= 10; i--)
    {
        printf("%d\n", i);
    }
    return 0;
}
