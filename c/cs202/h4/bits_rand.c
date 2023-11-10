#include <stdio.h>
#include <time.h>

int main(int argc, char argv[])
{
    srand(time(NULL));
    int k, x, y;
    printf("Interger: ");
    scanf("%d", &k);

    for (int i = 0; i < )
    x = k;

    printf("x % 10: %u\n", x % 10);

    x = (x << 3) ^ (3 * x + 1);
    printf("x % 10: %u\n", x % 10);

    k--;

}
