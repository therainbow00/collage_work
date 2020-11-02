/*
  Read from the console.  Sample transcript...

cs202@cs:~/solutions/h9$ ./d_hex.o
Enter in he(x) or unsigned (d)ecimal? x
Hex int: ff
hex: ff, decimal: 255

cs202@cs:~/solutions/h9$ ./d_hex.o
Enter in he(x) or unsigned (d)ecimal? 255
Invalid, expected x or d.  Goodbye.

cs202@cs:~/solutions/h9$ ./d_hex.o
Enter in he(x) or unsigned (d)ecimal? d
Decimal int: 255
hex: ff, decimal: 255

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

  printf("Enter in he(x) or unsigned (d)ecimal? ");
  char string[1];
  char hex[1];
  scanf("%s", string);
  char bits[] = "0x";
  unsigned char num = 0xff;
  int interger = 0xff;
  char result[101];


  if (string[0] == 'x')
  {
      printf("Hex int: ");
      scanf("%s", hex);
      printf("%s\n", hex);
      strcat(bits, hex);
      sprintf(result, "%x", *bits);
      //printf("%s\n", bits);
      //strcpy((char*) num, bits);
      //printf("%s\n", num);
      //interger = atoi(num);
      //printf("%d\n", interger);
      printf("hex: %#x, decimal: %d\n", result, result);
      printf("hex: %#x, decimal: %d\n", num, num);
      //printf("%d\n", atoi(bits));
      return 0;
  }
  else if (string[0] == 'd')
  {
      printf("Decimal int: %d\n", hex);
      printf("hex: %x, decimal: %d\n", hex, hex);
      return 0;
  }
  printf("Invalid, expected x or d.  Goodbye.\n");
  return 0;
}
