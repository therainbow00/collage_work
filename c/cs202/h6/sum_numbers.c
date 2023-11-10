#include <stdio.h>
#include <math.h>

int main()
{
    int i_num1, i_num2;
    float f_num1, f_num2;
    scanf("%d %d", &i_num1, &i_num2);
    scanf("%f %f", &f_num1, &f_num2);

    printf("%d %d\n", i_num1 + i_num2, i_num1 - i_num2);

    printf("%.1f %.1f\n", f_num1 + f_num2, f_num1 - f_num2);

    return 0;
}
