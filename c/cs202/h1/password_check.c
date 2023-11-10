// problem 11, password check

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("Password: ");
    char response[51], password[10] = "please";
    scanf("%s", response);
    strcmp(password, response);

    while (strcmp(password, response) != 0)
    {
        printf("Sorry, wrong. Try again.\n");
        printf("Password: ");
        scanf("%50s", response);
    }
    return 0;
}
