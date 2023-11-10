#include <stdio.h>

int main(void)
{
  int i;

  // Print the values 0 through 10 inclusive:

  // While-loop method:
  i = 0;
  while (i <= 10) {
    printf("%d\n", i);
    i = i + 1;
  }
  printf("---\n");

  // For-loop method:
  for (i = 0; i <= 10; i++) {
    printf("%d\n", i);
  }
  printf("---\n");

  // For-loop method in decreasing order:
  for (i = 10; i >= 0; i--) {
    printf("%d\n", i);
  }

  return 0;
}
