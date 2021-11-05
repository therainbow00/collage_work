#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define K	1024

int my_strlen(char s[])
{
  int len = 0;
  while(s[len] != '\0') len++;
  return len;
}

void my_puts(char s[])
{
  write(STDOUT_FILENO, s, my_strlen(s));
}

void cat(int fd)
{
  int r;
  char buf[K];

  while ( (r = read(fd, buf, K)) > 0) {
    write(STDOUT_FILENO, buf, r);
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    cat(STDIN_FILENO);
  } else {
    for(int i=1; i < argc; i++) {
      int fd = open(argv[i], O_RDONLY);
      if (fd < 0) {
	my_puts("Error opening file");
	my_puts(argv[i]);
	my_puts("\n");
	continue;
      }

      cat(fd);

      close(fd);
    }
  }

  exit(0);
}
