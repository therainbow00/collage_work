#include <stdio.h>
#include <stdlib.h>

void print_to_binary(int num)
{
    int mask = 1 << 32, count = 0, test = 0;
    while (mask)
    {
        if (num & mask || test > 0)
        {
            if (num & mask)
            {
                printf("1");
                count++;
                test = 1;
            }
            else
            {
                printf("0");
            }
        }
        mask >>= 1;
    }
    printf("\n");
    printf("%d\n", count);
}

int main(int argc, char *argv[])
{
    print_to_binary(atoi(argv[1]));
    return 0;
}
