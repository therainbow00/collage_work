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

  int i, j, k, count = 0, count_2 = 0, _true = 0, count3 = 0, array_num[50], array_num_2[50];
  //char array_num[50], array_num_2[50];
  if (argc == 2)
  {
      int length = (floor(log10(num))) + 1;
      printf("length: %d\n", length);
      for (i = 0; i < 50; i++)
      {
          if (num == 0)
          {
              printf("%d ", num);
          }
          //array_num[i] = num;
          //printf("after 'num == '0''\n");
          //array_num[i] = (char) num;
          //int result = num % 10;
          array_num[i] = num % 10;
          //printf("%c ", array_num[i]);
          num /= 10;
          count3++;;
      }
      //printf("\n");
      printf("count3 = %d\n", count3);
      //printf("sizeof(num) = %lu\n", sizeof(num));
      //array_num[i] = '\0';
      for (j = 0; j < count3; j++)
      {
          printf("%d ", array_num[j]);
          /*
          if (array_num[j] == NULL)
          {
              printf("after 'array_num[j] == 0'\n");
              printf("%d ", array_num[j]);
          }
          */
          count++;
          //array_num[i] = num;
          //num = num / 10;
      }
      printf("\n");

      //int count_2 = 0;
      for (k = count - 1; k >= 0; k--)
      {
          if (array_num[k])
          {
              array_num_2[count_2] = array_num[k];
              count_2++;
              //printf("%c\n", array_num[k]);
          }
          //array_num[i] = num;
          //num = num / 10;
      }

      for (int m = 0; m < count; m++)
      {
          printf("%d ", array_num_2[m]);
      }

      printf("\n");
      //int _true = 0;
      for (int l = 0; l < count; l++)
      {
          if (array_num[l] != array_num_2[l])
          {
              printf("not palindrome.\n");
              break;
          }
          else
          {
              _true = 1;
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
