#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <ctype.h>

#define K	1024

/**
 * To help with your conversion to nasm assembly:
 * Typedef:	real C type:
 * pid_t	int
 * size_t	unsigned long
 * ssize_t	long
 *
 * Both, O_RDONLY and STDIN_FILENO are equal to 0.
 * The macro for WEXITSTATUS(status) is: (((status) & 0xff00) >> 8)
 */
void waitforchild(void);
//void parent(int pfd[2]);
//void child(int pfd[2]);
/*
void waitforchild(void)
{
  int status;
  if (wait(&status) < 0) {
    perror("wait");
  }
  printf("Exit status of the child = %d\n", WEXITSTATUS(status));
}
*/
// Send something to the child:
void parent(int pfd[2])
{
  char buf[K];
  int status, fd, r;

  close(pfd[0]);
  fd = open("pipe.s", O_RDONLY);
  if (fd < 0) {
    perror("open");
    return waitforchild();
  }
  while ( (r = read(fd, buf, K)) > 0 ) {
    write(pfd[1], buf, r);
  }
  close(pfd[1]);
  close(fd);
  waitforchild();
}

// Reads info from the parent and does something with it:
void child(int pfd[2])
{
  char buf[K];
  int r;

  // This is important in order to get the EOF:
  close(pfd[1]);

  while ((r = read(pfd[0], buf, K)) > 0) {
    for(int i=0; i < r; i++)
      buf[i] = toupper(buf[i]);
    write(STDOUT_FILENO, buf, r);
  }
  close(pfd[0]);

  exit(42);
  // Do something;
  return;
}


int main(void)
{
  int pfd[2];

  if (pipe(pfd) < 0) {
    perror("pipe");
    return 1;
  }
  pid_t pid = fork();

  if (pid < 0) {
    perror("fork");
  }
  if (pid > 0) parent(pfd);
  else child(pfd);

  return 0;
}
