#include <stdio.h>

int main(void)
{
  printf("    2 3 4 5 6 7\n");
  printf("  -------------\n");
  for(int i = 0; i < 16; i++) {
    printf("%2X:", i);
    for(int j = 2; j < 8; j++) {
      int ch = (j<<4) + i;
      if (ch == 127) printf(" DEL");
      else printf(" %c", ch);
    }
    printf("\n");
  }
  
  return 0;
}
