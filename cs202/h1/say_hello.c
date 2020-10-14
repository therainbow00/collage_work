// problem 2, say hello to me

#include <stdio.h>

int main(int argc, char *argv[]) {
    char str[1];
    printf("What is your name?: \n");
    scanf("%s", str);
    printf("Hello %s! \n", str);
    return 0;
}
