#include <stdio.h>

void change(int x, int y)
{
    printf("x %d, y %d\n", x, y);
    x = x + 1;
    y = x + 1;
    printf("&x %p, &y %p\n", &x, &y);
}

int main(int argc, char *argv[])
{
    /* & - get the address
    * - get the value
    inverses of each
    */

    int local_variable = 4; // how mnay bits does int have? 4
    int another_var = 5;

    printf("local_variable: %d\n", local_variable);
    printf("&local_variable: %p\n", &local_variable);
    printf("&another_var: %p\n", &another_var);

    change(another_var, local_variable);

    printf("local_variable: %d\n", local_variable);
    printf("&local_variable: %p\n", &local_variable);
    printf("&another_var: %p\n", &another_var);

    change(another_var, local_variable);

    return 0;
}
