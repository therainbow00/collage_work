#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int emu;
int ape;
int bat = 13;
int cat = 100;
int dog;
int main(int argc, char *argv[])
{

  int *rat;

  printf("main %p value\n", &main);
  printf("main %p value\n", &main);

  printf("ape  %p\n", &ape);
  printf("bat  %p\n", &bat);
  printf("cat  %p\n", &cat);
  printf("dog  %p\n", &dog);
  printf("emu  %p\n", &emu);

  rat = malloc(24);

  return 0;
}
void fox(int hog)
{
  int jay;
  printf("hog  %p\n", &hog);
  printf("jay  %p\n", &jay);
}
