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
  //printf("i = %d\n", i);
  if (argc == 1)
  {
      printf("Usage: %s file1.txt file2.txt ...\n", argv[0]);
  }
  else if (argc == 2)
  {
      //printf("i = %d\n", i);
      char s[1001];
      //int line = 0;
      FILE *m;
      m = fopen(argv[1], "r");
      printf("** file: %s **\n", argv[1]);
      int length = strlen(m);
      for (int i = 0; i < length; i++)
      {
          fgets(s, 1001, m);
          printf("%s", s);
      }
      fclose(m);
      printf("**  end **\n");
  }
  else if (argc == 3)
  {
      printf("** file: %s **\n", argv[1]);
      char s[1001];
      //int line = 0;
      FILE *m;
      m = fopen("a_empty.c", "r");
      int length = strlen(m);
      for (int i = 0; i < length; i++)
      {
          fgets(s, 1001, m);
          printf("%s", s);
      }
      fclose(m);

      printf("**  end **\n");
      printf("** file: %s **\n", argv[2]);
      char s1[1001], c;
      FILE *n;
      n = fopen(argv[2], "r");
      int length_n = strlen(n);
      //c = fgetc(n);
      //int count = 0;
      for (int j = 0; j < length_n; j++)
      {
          //count++;
          //printf("%c\n", n[j]);
          //fscanf(n, "%s", s1);
          fgets(s1, 1001, n);
          printf("%s", s1);
          //puts(s1);
      }
      /*
      for (c = fgetc(n); c < 101; c = fgetc(n))
      {
          printf("%c", c);
      }
      */
      fclose(n);
      //printf("number of characters: %d\n", count);
      printf("**  end **\n");
  }
  return 0;
}
