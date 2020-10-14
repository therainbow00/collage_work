// problem 15, random coins

#include <stdio.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int heads = 0;
    for (int i = 0; i < 10; i++)
    {
        //printf("%d\n", rand() % 2);

        if (rand() % 2 == 0)
        {
            printf("Heads\n");
            heads++;
        }
        else
        {
            printf("Tails\n");
        }
    }
    printf("\nHeads counted: %d\n", heads);
    return 0;
}
