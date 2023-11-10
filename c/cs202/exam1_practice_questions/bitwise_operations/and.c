#include <stdio.h>

int main()
{
    printf("Interger: ");
    int num, num1;
    scanf("%d", &num);
    printf("Interger: ");
    scanf("%d", &num1);

    printf("%d & %d = %d\n", num, num1, num & num1);
}
