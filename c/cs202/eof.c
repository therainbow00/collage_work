#include <stdio.h>
#include <string.h>

int main()
{
    char c;
    int count = 0;

    while ((c = fgetc(stdin)) != EOF)
    {
        if (count == 3)
        {
            printf("*");
            count = 0;
        }
        else
        {
            printf("%c", c);
            count++;
        }
    }
    return 0;
}
