#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** (2pts)
 * Create a program that takes two integers (a and b) from the command line
 * and multiplies them in binary, printing the result.  You may only use
 * binary operators &, |, ^, <<, >> and addition.
 *
 * Example input/output:
 * ./p5 54 3
 * 162
 */

int main(int argc, char *argv[])
{
  if (argc < 3) {
    printf("Usage: p5 <a> <b>\n");
    return 0;
  }
  uint32_t a = atoi(argv[1]);
  uint32_t b = atoi(argv[2]);

  int result = 0;
  for (b; b != 0; b >>= 1)
  {
      if (b & 1) result += a;
      a <<= 1;
  }
  printf("%d\n", result);

  return 0;
}
