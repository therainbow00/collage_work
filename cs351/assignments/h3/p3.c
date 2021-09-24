#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/** (2pts)
 * In this assignment you may not use atoi or strtol() or any other libc
 * function to convert a string to a number.
 *
 * Make a program that implements an atoi like function, say ascii2int()
 * that takes a string and an integer base to convert the string to a number
 * of the given base, i.e. ascii2int("101",2) would convert 101 as a binary
 * number where ascii2int("101", 10) would convert 101 as a decimal number.
 *
 * Your function should handle bases from 2 though 16 (it does not need to
 * error check this input.)  It should stop processing the string if the
 * character is not a valid digit in the given base.
 *
 * The program should accept two strings, one the number to be converted
 * and a second base (always specified in decimal.)  Use the ascii2int()
 * function to covert both numbers and print the first number after
 * conversion.
 *
 * Example input/output:
 * ./p3 101 2
 * 5
 * ./p3 101 10
 * 101
 * ./p3 101 16
 * 257
 */


int ascii2int(char *str, int base)
{
    char digits[] = "0123456789ABCDEF";
    int value = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if ((str[i] - 'A' + 10) >= base)
            {
                break;
            }
            else
            {
                value *= base;
                value += digits[str[i] - 'A' + 10] - 'A' + 10;
            }
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            if ((str[i] - 'a' + 10) >= base)
            {
                break;
            }
            else
            {
                value *= base;
                value += digits[str[i] - 'a' + 10] - 'a' + 10;
            }
        }
        else
        {
            if ((str[i] - '0') >= base)
            {
                break;
            }
            else
            {
                value *= base;
                value += digits[str[i] - '0'] - '0';
            }
        }
    }
    return value;
}

/**
 * Do not modify the main function.  Base should always be evaluated as a base
 * 10 value, which is then used to determine the base that the first parameter
 * is evaluated by.
 */
int main(int argc, char *argv[])
{
  if (argc < 3) {
    printf("Usage: p3 <integer> <base>\n");
    return 0;
  }

  int base = ascii2int(argv[2], 10);
  printf("%d\n", ascii2int(argv[1], base));


  return 0;
}
