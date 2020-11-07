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
  int hex;
  scanf("%x", &hex);
  printf("In binary: ");
  //unsigned int n;
  //printf("enter the no ( max range 255)\n");
  //scanf("%d",&n);
  //int c[101] = {0};
  //int i = 101 - 1;
  //printf("binary representation is: ");
  //printf("%x\n", hex);
  //int count = 0;
  //printf("%x, %d\n", hex, hex);
  char first_string[101], first_string1[101];
  //char first_string1[101];
  int first;
  for (int i = 31; i >= 0; i--)
  {
      printf("%x", (hex >> i) & 1);
      //first += (hex >> i) & 1;
      //sprint((hex >> i) & 1, first_string, 2);
      //sprint(first_string, (hex >> i) & 1, "%s");
      //printf("\n");
      sprintf(first_string, "%x", (hex >> i) & 1);
      //printf("\n%c\n", first_string);
      strcpy(first_string1, first_string);
      //printf("\n%s", first_string1);
      //&first += (hex >> i) & 1;
      //printf("%x ", pow(2, i));
      //count++;
      //hex >>= i;
  }
  for (int j = 0; j < strlen(first_string1); j++)
  {
      printf("%s", first_string1[j]);
  }
  //printf("\nfirst: %s", first_string1);
  //printf("\n%x", first);
  /*
  printf("\nhere");
  for (int k = 0; k < strlen(first_string1); k++)
  {
      printf("\nfirst: %s", first_string1[k]);
  }
  printf("\nhere (1)");
  */
  printf("\n");
  /*
  char second_string[101];
  char second_string1[101];
  int second[101];
  for (int j = 0; j < 32; j++)
  {
      printf("%x", (hex >> j) & 1);
      sprintf(second_string, "%s", (hex >> j) & 1);
      strcpy(second_string1, second_string);
      //itoa((hex >> j) & 1, second_string, 2);
      //&second += (hex >> j) & 1;
  }
  printf("\nsecond: %s", second_string1);
  printf("\n");
  */

  //printf("%d\n", count);
  /*
  while (hex)
  {
      if (hex & 1)
      {
          printf("1");
      }
      else
      {
          printf("0");
      }
      hex >>= 1;
  }
  printf("\n");
  */
  /*
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
  */

  return 0;
}
