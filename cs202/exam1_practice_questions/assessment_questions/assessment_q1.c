/* Give C code that takes integers k1 and k2 as input and prints out (1+3+5+...(2*k+1)) for each integer k in between k1 and k2.  For k1=2 and k2=5, your program would output -

4
9
16
25
*/

#include <stdio.h>

int main()
{
    int k1, k2, total = 0, i;
    printf("Interger: ");
    scanf("%d", &k1);
    printf("Interger: ");
    scanf("%d", &k2);

    for (i = 0; i < k2; i++)
    {
        total += 2 * i + 1;

        if (i >= k1)
        {
            printf("%d\n", total);
        }
    }

    return 0;
}
