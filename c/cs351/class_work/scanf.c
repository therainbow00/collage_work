#include <stdio.h>

int main(void)
{
    /*
     * Print a prompt to prompt the user to input something:
    */
    printf("Input a integer: ");
    int num;

    /*
     * Store the read integer into 'rum'. The & specifies the "address"
     * or location of rum in memory. This "Pass by reference".
    */
    scanf("%x", &num);

    printf("The integer you input was: %d\n", num);
    return 0;
}
