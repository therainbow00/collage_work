/*
  Read from command-line arguments.  Sample transcript...

cs202@cs:~/solutions/h9$ ./e_bits.o 
Usage: ./e_bits.o n i

cs202@cs:~/solutions/h9$ ./e_bits.o 8 3
Number in hex: 0x8
3th bit from the right is: 1

cs202@cs:~/solutions/h9$ ./e_bits.o 8 2
Number in hex: 0x8
2th bit from the right is: 0

cs202@cs:~/solutions/h9$ ./e_bits.o 3 2
Number in hex: 0x3
2th bit from the right is: 0

cs202@cs:~/solutions/h9$ ./e_bits.o 3 1
Number in hex: 0x3
1th bit from the right is: 1

cs202@cs:~/solutions/h9$ ./e_bits.o 3 0
Number in hex: 0x3
0th bit from the right is: 1

cs202@cs:~/solutions/h9$ ./e_bits.o 255 6
Number in hex: 0xff
6th bit from the right is: 1

cs202@cs:~/solutions/h9$ ./e_bits.o 255 40
Invalid value for i, should be between 0 and 31.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  
  return 0;
}
