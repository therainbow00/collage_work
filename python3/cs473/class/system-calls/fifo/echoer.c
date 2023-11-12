
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

  if( argc < 2 ) {
    printf("usage: %s <fifoPath>\n", argv[0]);
    return 0;
  }

  char *fifoPath = argv[1];


  if( mkfifo(fifoPath, 0666) == -1 && errno != EEXIST ) {
    perror("mkfifo");
    return -1;
  }

  int fifoFd = open(fifoPath, O_RDONLY);

  //FILE *fifo = fopen(fifoPath, "r");

  //if( fifo == NULL ) {
  //  perror("fopen");
  //  return -1;
  //}

  for(;;) {
    char buf[BUFFER_SIZE];

    //int charsRead = fread(buf, sizeof(char), BUFFER_SIZE - 1, fifo);

    int charsRead = read(fifoFd, buf, BUFFER_SIZE - 1);

    // printf("charsRead: %d\n", charsRead);
    
    buf[charsRead] = 0;

    printf("%s\n", buf);
  }
}
