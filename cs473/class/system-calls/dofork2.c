#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  
  printf("pre-split\n");

  int childpid = fork();

  // you are the parent
  if( childpid ) {
    printf("parent: after fork1, pid == %d\n", childpid);
  } else {
    printf("child: after fork1, pid == %d\n", childpid);
  }

  childpid = fork();

  // you are the parent
  if( childpid ) {
    printf("parent: after fork2, pid == %d\n", childpid);
  } else {
    printf("child: after fork2, pid == %d\n", childpid);
  }

}
