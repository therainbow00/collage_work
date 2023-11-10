int bittest(uint32_t num, int32_t i)
{
  return num & (1<<i);
}

void printbinary(uint32_t num)
{
  for(int i=7; i >= 0; i--) {
    // Hint: bittest can probably mostly be replaced by the 'test' instruction:
    if (bittest(num, i)) putchar('#');
    else putchar(' ');
  }
}

int main(int argc, char *argv[])
{
  int32_t r, fd;
  uint8_t num;

  /**
   * Note: You will probably only want to attempt to access argc/argv in your
   * _start function, as calling a function will modify the rsp register when
   * the return value is pushed onto the stack.
   */
  // Hint: argc is located in memory at rsp, value of argc is [rsp]:
  if (argc < 2) {
    puts("Usage: h5 <file>\n");
    exit(1);
  }

  // Hint: argv[1] is located in memory at [rsp+16]:
  fd = open(argv[1], O_RDONLY);
  if (fd < 0) {
    puts("Unable to open file for reading.\n");
    exit(1);
  }

  while(1) {
    r = read(fd, &num, sizeof(num));
    if (r != 1) break;

    printbinary(num);
    putchar('\n');
  }

  close(fd);
  exit(0);
}
