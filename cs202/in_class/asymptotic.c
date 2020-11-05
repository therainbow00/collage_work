#include <stdio.h>
#include <math.h>

long int squared(long int n) {
  return n*n;
}

long int linear(long int n) {
  return n;
}

long int exptwo(long int n) {
  return (1 << n);
}

long int logtwo(long int n) {
  long int x = (long int) log2(n);
  retur (x * x * 3);
}


int main(long int argc, char *argv[]) {

  long int max_n = 400;

  printf("%10s| %10s %10s %10s %10s\n", "n", "log2", "linear", "squared", "exp2");

  for(long int n=1; n <= max_n; n++) {

    printf("%10ld| %10ld %10ld %10ld %10ld\n", n, logtwo(n), linear(n), squared(n), exptwo(n));
  }

  return 0;
}
