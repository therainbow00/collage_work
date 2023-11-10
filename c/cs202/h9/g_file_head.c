/*
  Read from command-line arguments.  Sample transcript...

cs202@cs:~/solutions/h9$ ./g_file_head.o
Usage: ./g_file_head.o file1.txt file2.txt ...

cs202@cs:~/solutions/h9$ ./g_file_head.o a_empty.c
** file: a_empty.c **
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
**  end **

cs202@cs:~/solutions/h9$ ./g_file_head.o a_empty.c /u1/junk/kinne/text-samples/shakespeare.txt
** file: a_empty.c **
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
**  end **
** file: /u1/junk/kinne/text-samples/shakespeare.txt **
The Project Gutenberg EBook of The Complete Works of William Shakespeare, by
William Shakespeare

This eBook is for the use of anyone anywhere at no cost and with
almost no restrictions whatsoever.  You may copy it, give it away or
**  end **

cs202@cs:~/solutions/h9$ ./g_file_head.o nofile a_empty.c nofile2
** file: nofile **
** unable to open **
** file: a_empty.c **
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
**  end **
** file: nofile2 **
** unable to open **

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  if (argc <= 1)
  {
      printf("Usage: %s file1.txt file2.txt ...\n", argv[0]);
  }
  else if (argc == 2)
  {
      char s[1001];
      FILE *m;
      m = fopen(argv[1], "r");
      printf("** file: %s **\n", argv[1]);
      int length = strlen(m);
      for (int i = 0; i <= length; i++)
      {
          fgets(s, 1001, m);
          printf("%s", s);
      }
      fclose(m);
      printf("**  end **\n");
  }
  else if (argc >= 3)
  {
      printf("** file: %s **\n", argv[1]);
      char s[1001];
      FILE *m;
      m = fopen(argv[1], "r");
      if (m == NULL)
      {
          printf("** unable to open **\n");
      }
      else
      {
          int length = strlen(m);
          for (int i = 0; i <= length; i++)
          {
              fgets(s, 1001, m);
              printf("%s", s);
          }
          fclose(m);
          printf("**  end **\n");
      }
      printf("** file: %s **\n", argv[2]);
      char s1[1001];
      FILE *n;
      n = fopen(argv[2], "r");
      if (n == NULL)
      {
          printf("** unable to open **\n");
      }
      else
      {
          int length_n = strlen(n);
          for (int j = 0; j <= length_n; j++)
          {
              fgets(s1, 1001, n);
              printf("%s", s1);
          }
          fclose(n);
          printf("**  end **\n");
      }
      if (argv[3] == NULL)
      {
          return 0;
      }
      else
      {
          printf("** file: %s **\n", argv[3]);
          char s2[1001];
          FILE *x;
          x = fopen(argv[3], "r");
          if (x == NULL)
          {
              printf("** unable to open **\n");
          }
          else
          {
              int length_n = strlen(n);
              for (int j = 0; j <= length_n; j++)
              {
                  fgets(s1, 1001, n);
                  printf("%s", s1);
              }
              fclose(n);
              printf("**  end **\n");
          }
      }
      if (argv[4] == NULL)
      {
          return 0;
      }
      else
      {
          printf("** file: %s **\n", argv[4]);
          char s3[1001];
          FILE *g;
          g = fopen(argv[4], "r");
          if (g == NULL)
          {
              printf("** unable to open **\n");
          }
          else
          {
              int length_g = strlen(g);
              for (int r = 0; r <= length_g; r++)
              {
                  fgets(s3, 1001, g);
                  printf("%s", s3);
              }
              fclose(g);
              printf("**  end **\n");
          }
      }
  }
  return 0;
}
