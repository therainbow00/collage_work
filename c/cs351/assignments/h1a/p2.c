#include <stdio.h>

/** 1pt
 * Complete the main function to:
 *  - Print a prompt that says: "Input a hex number: " (no newline at the end)
 *    - The number may be a 32 bit unsigned integer ('unsigned int' type)
 *  - Use scanf (lesson c1) to read a hexadecimal number from the user
 *    - Don't forget to prefix the variable with a & (ampersand), that tells
 *      the program where in memory the variables value is stored at.
 *   - Print out the read value in decimal, octal and uppercase hexadecimal.
 *     - Note that the decimal value should be printed as an unsigned integer.
 */

int main(void)
{
    printf("Input a hex number: ");
    unsigned int u;
    scanf("%x", &u);

    printf("The number you entered:\n");
    printf("    Decimal: %u\n", u);
    printf("      Octal: %o\n", u);
    printf("Hexadecimal: %X\n", u);
}
