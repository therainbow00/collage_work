#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/** 2 pts
 * Write a C program to check whether the number provided on the command line
 * (num) is a palindrome or not (i.e. has the same digits both forward and
 * backward.)  You are not allowed to use the original argv[1] string, you
 * may only use num and any other numbers, arrays or strings that you may
 * choose to create.  If the number is a palindrome print "palindrome\n", if
 * the number is not, then print "not palindrome\n".
 *
 * Example input/output:
 * ./p2 1234321
 * palindrome
 * ./p2 155
 * not palindrome
 */

int main(int argc, char *argv[])
{
  /* Do not modify the following: */
  if (argc < 2) {
    printf("Usage: p2 <number>\n");
    return 1;
  }
  int num = abs(atoi(argv[1]));
  /* Do not modify the above. */

  char str[32];
  int r = 0;
  do {
    str[i++] = num % 10;
    num = num / 10;
  } while (num > 0);
  i--;
  int l = 0, pf = 1;
  while (l < r)
  {
      if (str[l++]) != str[r--]
      {
          pf = 0;
          break;
      }
  }
  if (pf) printf("palindrome.\n");
  else printf("not palindrome.\n");

