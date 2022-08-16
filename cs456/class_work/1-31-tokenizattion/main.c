#include "expr.h"

int main(void)
{
  char buf[K+1];
  int r;

  while ( (r = read(STDIN_FILENO, buf, K)) > 0) {
    buf[r] = '\0';
    int value = expr(buf);
    printf("%d\n", value);
  }
  return 0;
}
