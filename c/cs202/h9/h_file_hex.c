/*
  Read from command-line arguments.  Sample transcript...

cs202@cs:~/solutions/h9$ ./h_file_hex.o
Usage: ./h_file_hex.o file.txt

cs202@cs:~/solutions/h9$ ./h_file_hex.o nofile
** unable to open **

cs202@cs:~/solutions/h9$ ./h_file_hex.o a_empty.c
#include <stdio.h>                        0x23696e63 6c756465  203c7374 64696f2e  683ea
#include <stdlib.h>                       0x23696e63 6c756465  203c7374 646c6962  2e683ea
#include <string.h>                       0x23696e63 6c756465  203c7374 72696e67  2e683ea
#include <time.h>                         0x23696e63 6c756465  203c7469 6d652e68  3ea
#include <ctype.h>                        0x23696e63 6c756465  203c6374 7970652e  683ea
                                          0xa
int main(int argc, char *argv[]) {        0x696e7420 6d61696e  28696e74 20617267  632c2063 68617220  2a617267 765b5d29  207ba
                                          0xa
  return 0;                               0x20207265 7475726e  20303ba
}                                         0x7da

cs202@cs:~/solutions/h9$ ./h_file_hex.o a_empty.o
.ELF...                                   0x7f454c46 211
                                          0x
.                                         0x2
-                                         0x2d
..                                        0xfffffff82
.                                         0x16
 uv.                                      0x2075763 a
th..                                      0x746821
...Y..                                    0xffffffae5159 22
                                          0x
                                          0x
                                          0x

Notes:
* Use getline to read one line at a time
* For each line, you
  a) print the printable characters (and '.' for non-printable characters), and don't print the \n
  b) print spaces up so the line so far has been 40 characters, and print an extra two spaces past that
  c) loop through the line again to print the character in hex, adding an extra ' ' after each 4 bytes and another extra space after each 8 bytes
* Use the isprint function to test if printable, use %x to print the character in hex
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  if (argc == 1)
  {
      printf("Usage: %s file.txt\n", argv[0]);
  }
  if (argc == 2)
  {
      FILE *file;
      file = fopen(argv[1], "r");
      if (file == NULL)
      {
          printf("** unable to open **\n");
          return 0;
      }
      else
      {
          char str[101], c, string[] = "0x";
          //int length_file = strlen(file);
          //c = fgetc(file);
          /*
          while ((c = fgetc(file)) != EOF)
          {

              printf("%c", c);
              //printf("%p", c);
          }
          */
          printf("%s", string);
          while ((c = fgetc(file)) != EOF)
          {
              printf("%x", c);
          }

          //printf("%s", string);
          /*
          for (int i = 0; i <= sizeof(file); i++)
          {
              c = fgetc(file);
              printf("%c", c);
          }
          printf("%s", string);
          for (int j = 0; j <= sizeof(file); j++)
          {
              c = fgetc(file);
              printf("%x", c);
          }
          */
          //printf("\n");
          //printf("%d", sizeof(file));

          /*
          for (c = fgetc(file); c != EOF; c = fgetc(file))
          {
              printf("%c", c);
              //printf("%p\n", c);
              //printf("\t");
              //printf("\t%p", c);
          }
          */
          /*
          for (int i = 0; i <= sizeof(file); i++)
          {
              //str[i] = c;
              //fgets(str, 101, file);
              //printf("%s", str);
              printf("%p", c);
              //c = fgetc(file);
          }
          */
          /*
          for (int j = 0; j < strlen(str); j++)
          {
              printf("%s", str[j]);
          }
          */
          printf("\n");
          fclose(file);
      }

  }
  return 0;
}
