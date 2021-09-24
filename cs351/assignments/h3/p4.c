#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define K	1024

/** (2pts)
 * Make a program that accepts two numbers from the command line, an integer
 * and a base.  Convert the first number to a string in the given base, then
 * output the string.  Base may range from 2 to 16.  You may use atoi(), but
 * you may not use %d,%x or %o in printf or sprintf to directly print any
 * numbers.
 *
 * Example input/output:
 * ./p4 101 2
 * 1100101
 * ./p4 65535 16
 * FFFF
 */

int main(int argc, char *argv[])
{
  if (argc < 3) {
    printf("Usage: p4 <integer> <base>\n");
    return 0;
  }

  int num = atoi(argv[1]), base = atoi(argv[2]);
  char str[K], digits[] = "0123456789ABCDEF";
  //strlen(int_str);
  //int i;
  //str[i] = '\0';

  //char digits[] = "0123456789ABCDEF";
  //printf("strlen(%lu) - 1 = %lu\n", strlen(str), strlen(str) - 1);
  int i = 0;
  for (i = strlen(str) - 1; i > 0; i--)
  {

      if (num == 0)
      {
          str[i] = '\0';
          for (int j = 0; j < strlen(str) / 2; j++)
          {
              char temp = str[j];
              str[j] = str[strlen(str)-j-1];
              str[strlen(str)-j-1] = temp;
          }
          printf("%s\n", str + i);
          break;
      }
      else
      {
          int d = num % base;
          str[i] = digits[d];
          num /= base;
      }
  }
  //printf("%lu\n", strlen(str));

  return 0;
}
