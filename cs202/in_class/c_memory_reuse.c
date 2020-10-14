#include <stdio.h>

void magic()
{
    int x;
    printf("In magic. Note: &x = %p\n", &x);
    printf("You are thinking of a number, perhaps %d.\n", x);
    printf("Okay, noew tell me an interger: ");
    scanf("%d", &x);
    printf("\n");
}

void something_else()
{
    int y;
}

int main(int argc, char *argv[])
{
    magic();
    magic();
    magic();

    int z;
    int w;
    int v;

    printf("%p\n%p\n%p\n")

    return 0;
}
