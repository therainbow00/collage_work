#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "I have 5 letters to my name";
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
        {
            printf("index %d is: space\n", i);
        }
        else
        {
            printf("index %d is: %c\n", i, string[i]);
        }
    }
}
