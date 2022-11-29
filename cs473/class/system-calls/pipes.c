#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  
  printf("pre-split\n");

  int pipefds[2];

  if( pipe(pipefds) < 0 ) {
    perror("pipe");
    exit(-1);
  }

  int readfd = pipefds[0];
  int writefd = pipefds[1];

  int childpid = fork();

  // you are the parent
  if( childpid ) {
    close(readfd);
    
    printf("parent: writing 'hello'\n");

    write(writefd, "hello", 5);

    close(writefd);

  } else {
    close(writefd);

    char buf[BUFSIZ];

    int bytesRead = read(readfd, buf, BUFSIZ - 1);

    if(bytesRead < 0 ) {
      perror("read");
      exit(-1);
    }

    buf[bytesRead] = 0;

    printf("child receiving: %s\n", buf);

    close(readfd);
  }
}
