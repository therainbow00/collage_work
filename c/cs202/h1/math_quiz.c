// problem 16, math quiz

#include <stdio.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int left = rand() % 10, right = rand() % 10, correct, response;
    correct = left + right;

    printf("%d + %d = ", left, right);
    scanf("%d", &response);

    while (response != correct)
    {
        printf("Sorry, wrong. Try again.\n");
        printf("%d + %d = ", left, right);
        scanf("%d", &response);
    }

    return 0;
}
