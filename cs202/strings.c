#include <stdio.h>
#include <string.h>

int main()
{
    char str[51];
    int i, letter_count = 0, character_count = 0;
    printf("Enter a string (max characters: 50): ");

    fgets(str, 50, stdin);
    //scanf("%s", str); // ends when it encounters whitespace. whitespace = ' ' and \t

    //printf("string: %s\n", str);
    for (i = 0; i < strlen(str); i++)
    {
        if (i == (strlen(str) - 1))
        {
            printf("str[%d]: NULL\n", i);
        }
        else if (str[i] == ' ')
        {
            printf("str[%d]: space\n", i);
        }
        else
        {
            printf("str[%d]: %c\n", i, str[i]);
        }
        character_count++;

        if (isalpha(str[i]))
        {
            letter_count++;
        }
    }

    printf("\n------------------------------\n\n");

    for (int j = strlen(str) - 1; j > 0; j--)
    {
        if (j == strlen(str))
        {
            printf("str[%d]: NULL\n", j);
        }
        else if (str[j] == ' ')
        {
            printf("str[%d]: space\n", j);
        }
        else
        {
            printf("str[%d]: %c\n", j, str[j]);
        }
    }

    printf("Number of characters (a - z) in string: %d\n", letter_count);
    printf("Number of characters in string: %d\n", character_count);

    return 0;
}
