#include <stdio.h>

void f(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main()
{
    int first = 3, second = 5;
    printf("first: %d second %d\n", first, second);

    f (&first, &second);

    printf("first: %d second %d\n", first, second);
    return 0;
}
