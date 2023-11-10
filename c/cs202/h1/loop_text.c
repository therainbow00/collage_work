// problem 3, loop through text

#include <stdio.h>

int main(int argc, char *argv[])
{
    char input[31];
    int index;

    printf("Enter the string value\n");
    fgets(input, 31, stdin);

    for(index = 0; input[index] != '\0'; index++)
    {
        printf("%c", input[index]);
        printf("\n");

    }
    printf("Done!");

    return 0;
}
