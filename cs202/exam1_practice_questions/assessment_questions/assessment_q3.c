// Write C code that is given an integer k and finds the "right-most" 1 in its binary representation and outputs that number as a decimal.  E.g., for 24, the output would be 8, and for k=8 the output would also be 8.  For k=12, the answer would be 4, and for k=10 the answer would be 2

#include <stdio.h>

int main()
{
    int num;
    printf("Interger: ");
    scanf("%d", &num);

    printf("%d\n", num >> 2);
}
