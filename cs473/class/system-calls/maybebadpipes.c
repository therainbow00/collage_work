#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  
  printf("pre-split\n");

  int childpid = fork();

  int pipefds[2];

  pipe(pipefds);

  // you are the parent
  if( childpid ) {
    printf("parent (r/w): %d / %d\n", pipefds[0], pipefds[1]);
    sleep(2);
  } else {
    printf("child (r/w): %d / %d\n", pipefds[0], pipefds[1]);
  }


  close(pipefds[0]);
  close(pipefds[1]);
}
