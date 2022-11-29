

#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if( argc < 2 ) {
    printf("usage: %s <socket-path>\n", argv[0]);
    return 0;
  }

  char *socketPath = argv[1];

  int listenerFd = socket(AF_UNIX, SOCK_STREAM, 0);

  struct sockaddr_un address;
  
  address.sun_family = AF_UNIX;
  strncpy(address.sun_path, socketPath, sizeof(address.sun_path) - 1);

  if( bind(listenerFd, (struct sockaddr *) &address, sizeof(struct sockaddr_un)) == -1 ) {
    perror("bind");
    return -1;
  }


  close(listenerFd);
}
