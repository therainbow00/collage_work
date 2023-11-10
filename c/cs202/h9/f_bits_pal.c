/*
  Read from console.  Sample transcript...

cs202@cs:~/solutions/h9$ ./f_bits_pal.o
Enter a number in hex: f0f00f0f
In binary: 11110000111100000000111100001111
palindromic bits

cs202@cs:~/solutions/h9$ ./f_bits_pal.o
Enter a number in hex: f0f0f0f0
In binary: 11110000111100001111000011110000
not palindromic bits

cs202@cs:~/solutions/h9$ ./f_bits_pal.o
Enter a number in hex: 80000001
In binary: 10000000000000000000000000000001
palindromic bits

cs202@cs:~/solutions/h9$ ./f_bits_pal.o
Enter a number in hex: 80000008
In binary: 10000000000000000000000000001000
not palindromic bits

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[]) {
  printf("Enter a number in hex: ");
  int hex, first[101], second[101], i, j, k, l, m;
  scanf("%x", &hex);
  printf("In binary: ");
  for (i = 31; i >= 0; i--)
  {
      printf("%x", (hex >> i) & 1);

  }
  printf("\n");
  for (j = 31; j >= 0; j--)
  {
      first[j] = (hex >> j) & 1;

  }
  for (k = 0; k < 32; k++)
  {
      second[k] = (hex >> k) & 1;
  }

  for (l = 0, m = 31; l < 32, m >= 0; l++, m--)
  {
      if (first[m] != second[l])
      {
          printf("not palindromic bits\n");
          return 0;
      }
  }
  printf("palindromic bits\n");

  return 0;
}
