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

  int array_num[50], array_num_2[50], i, j, k, count = 0, count_2 = 0, _true = 0, count3 = 0;
  //char array_num[50], array_num_2[50];
  if (argc == 2)
  {
      int length = floor(log10(num)) + 1;
      if (num == 0)
      {
          length = 1;
      }
      //printf("length: %d\n", length);
      //printf("num: %d\n", num);
      for (i = 0; i < length; i++)
      {
          //array_num[i] = num;
          //printf("after 'num == '0''\n");
          //array_num[i] = (char) num;
          array_num[i] = num % 10;
          //printf("%d ", array_num[i]);
          num /= 10;
          count3++;;
      }
      //printf("\n");
      //printf("count3 = %d\n", count3);
      //printf("sizeof(num) = %lu\n", sizeof(num));
      //array_num[i] = '\0';

      for (j = 0; j < length; j++)
      {

          if (array_num[j] == 0)
          {
              //printf("after 'array_num[j] == 0'\n");
              printf("0 ");
          }
          else
          {
              printf("%d ", array_num[j]);
          }

          //count++;
          //array_num[i] = num;
          //num = num / 10;
      }

      printf("\n");

      //int count_2 = 0;
      //printf("count - 1: %d\n", count - 1);
      for (k = length - 1; k >= 0; k--)
      {
          if (array_num[k])
          {
              array_num_2[count_2] = array_num[k];
              printf("%d ", array_num_2[count_2]);
          }
          else
          {
              array_num_2[count_2] = 0;
              printf("0 ");
          }
          //count_2++;
          //array_num[i] = num;
          //num = num / 10;
      }
      printf("\n");


      printf("=====================\n");
      for (int m = 0; m < length; m++)
      {
          if (array_num_2[m] == 0)
          {
              printf("0 ");
          }
          else
          {
              printf("%d ", array_num_2[m]);
          }
      }
      printf("\n");
      printf("=====================\n");

      //printf("\n");
      //int _true = 0;
      for (int l = 0; l < length; l++)
      {
          printf("array_num[%d] = %d (==) array_num_2[%d] = %d\n", l, array_num[l], l , array_num_2[l]);
          if (array_num[l] == array_num_2[l])
          {
              _true = 1;
          }
          else
          {
              printf("not palindrome.\n");
              _true = 0;
              break;
          }
      }
      if (_true == 1)
      {
          printf("palindrome.\n");
      }

      //printf("%d\n", num);
  }
  return 0;
}
