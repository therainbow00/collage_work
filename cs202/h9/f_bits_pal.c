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

int main(int argc, char *argv[]) {
  printf("Enter a number in hex: ");
  int hex, c[101] = {0}, i = 101 - 1;
  scanf("%x", &hex);
  printf("In binary: ");
  //unsigned int n;
  //printf("enter the no ( max range 255)\n");
  //scanf("%d",&n);
  //int c[101] = {0};
  //int i = 101 - 1;
  //printf("binary representation is: ");
  while (hex != 0)
  {
      c[i--] = hex & 1;
      hex = hex >> 1;
  }
  for (int j = 0; j < 101; j++)
  {
      printf("%d", c[j]);
  }
  printf("\n");
  for (int j = 0, k = 101 - 1; j < k; j++, k--)
  {
      if (c[j] != c[k])
      {
          printf("Not palindrome\n");
          return 0;
      }
  }
  printf("it's palindrome\n");

  return 0;
}
