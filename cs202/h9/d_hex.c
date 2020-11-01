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
  scanf("%s", string);
  unsigned char hex = 0xff;

  if (string[0] == 'x')
  {
      printf("Hex int: %x\n", hex);
      printf("hex: %x, decimal: %d\n", hex, hex);
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
