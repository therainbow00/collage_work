#include <stdio.h>

int main()
{
    printf("Interger: ");
    int num, num1;
    scanf("%d", &num);
    printf("Interger: ");
    scanf("%d", &num1);

    printf("%d\n", num & num1);
}
