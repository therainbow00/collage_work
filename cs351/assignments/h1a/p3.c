#include <stdio.h>

/** 1pt
 * Complete the main function to:
 *  - Print a prompt that says: "Input a hex number: " (no newline at the end)
 *    - The number may be a 32 bit unsigned integer ('unsigned int' type)
 *    - Same as from h2.c
 *  - Print the input value in binary by making a loop over the values 31 down
 *    to 0 and (i.e. decreasing):
 *    - Test each bit in the value read against (1<<i) where i is the current
 *      loop value.  (Binary lesson 1)
 *    - Use a if statement in the loop to print a 1 or a 0 depending on what
 *      the test above produces. (C lesson 2)
 *  - Print the newline after the loop, not inside of the loop.
 */

int main(void)
{
    printf("Input a hex number: ");
    unsigned int hex_num, result, i;
    scanf("%x", &hex_num);

    //printf("Input a number: ");
    //scanf("%d", &num);

    printf("In binary: ");
    //printf("%d", u & (1 << num));
    for (i = 31; i > 0; i--)
    {
        //printf("%x", hex_num & (1 << i));

        if ((hex_num & (1 << i)) != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }

    }
    printf("\n");
    return 0;
}
