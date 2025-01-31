#include <stdio.h>

/**
 * A brief reminder of how command line arguments work.  The number of white-
 * space separated words (including the command word) that are present on the
 * command line is given by argc (ARGument Count), and each word is in the
 * NULL terminated array of strings argv (ARGument Vector), argv[0] is always
 * the command itself.
 * 
 * You should always check argc to make sure you have enough words to do what
 * you want to do with argv, before you attempt to do anything with argv, or
 * you may cause a segmentation fault attempting trying to access beyond the
 * valid range of the argv array.
 */
int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: %s <words...>\n", argv[0]);
    return 0;
  }

  int i;
  printf("argc = %d\n", argc);
  for(i=0; i < argc; i++) {
    printf("argv[%d] = \"%s\"\n", i, argv[i]);
  }
  printf("argv[%d] = NULL\n", i);

  return 0;
}
