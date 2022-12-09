
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE     4096
#define TRUE            1

void usage(char *argv[]) {
  printf("usage: %s <port-number>\n", argv[0]);
}

int main(int argc, char *argv[]) {
  if( argc < 2 ) {
      usage(argv);
      return 0;
  }

  struct sockaddr_in server_addr;
  int port = atoi(argv[1]);
  int client_socket;
  
  char buffer[BUFFER_SIZE];

  if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
      perror("socket");
      return -1;
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(port);

  int con = connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (con < 0)
  {
      perror("connect");
      return -1;
  }
  
  while (TRUE)
  {
      scanf("%s", buffer);
      
      if (strcmp(buffer, "quit") == 0) break;
      else if (send(client_socket, buffer, BUFFER_SIZE, 0) < 0)
      {
          perror("send");
          break;
      }
  }
  close(client_socket);
  return 0;
}
