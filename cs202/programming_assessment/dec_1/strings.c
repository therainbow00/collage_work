#include <stdio.h>
#include <string.h>

int main()
{
    char str[51];
    int x, y;
    printf("Enter a string (max characters: 50): ");

    fgets(str, 50, stdin);

    for (x = 0; x < strlen(str); x++)
    {
        for (y = 0; y <= x; y++)
        {
            printf("%c", str[y]);
        }
        printf("\n");
    }

    return 0;
}
