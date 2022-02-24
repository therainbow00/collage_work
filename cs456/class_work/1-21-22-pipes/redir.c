#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int redir(int newfd, char *file, int flags, int mode)
{
//  close(newfd);
//  open(file, flags, mode);
  int oldfd = open(file, flags, mode);
  dup2(oldfd, newfd);
}

int main(void)
{
  redir(STDOUT_FILENO, "output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  printf("Hello, world!\n");

  return 0;
}
