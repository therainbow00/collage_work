
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
#define MAX_N_TOKENS    10
#define MAX_CONNECTIONS 1024
#define TRUE            1

void usage(int argc, char *argv[]) {
  printf("usage: %s <port-number>\n", argv[0]);
}

int main(int argc, char *argv[]) {
  if( argc < 2 ) {
      usage(argc, argv);
      return 0;
  }

  struct sockaddr_in addr;
  int port = atoi(argv[1]);
  int socket_fd;
  
  char buffer[BUFFER_SIZE];

  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
      perror("socket_fd");
      return -1;
  }

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(port);

  if ((bind(socket_fd, (struct sockaddr*)&addr, sizeof(addr))) < 0)
  {
      perror("bind");
      return -1;
  }

  struct connection *clients; // clients linked list

  struct pollfd clientFds[MAX_CONNECTIONS];
  int numberClients = 0;
  
  struct pollfd socketfd[100];
  socketfd->fd = socket_fd;
  socketfd->events = POLLIN;
  socketfd->revents = 0;

  if ((listen(socket_fd, MAX_CONNECTIONS)) < 0)
  {
      perror("listen");
      return -1;
  }
  
  clientFds[numberClients] = *socketfd;
  numberClients++;

  for(;;) {

      int return_events = poll(clientFds, numberClients, -1);
      if (return_events < 0)
      {
          perror("poll");
          return -1;
      }

      if (clientFds[0].revents & POLLIN)
      {
          int new_accept = accept(clientFds[0].fd, NULL, NULL);
          
          struct pollfd new_accept_fd;
          new_accept_fd.fd = new_accept;
          new_accept_fd.events = POLLIN;
          new_accept_fd.revents = 0;
          
          clientFds[numberClients++] = new_accept_fd;
          return_events -= 1;
      }
      
      int current_poll_fd = 1;
      while (return_events > 0 && current_poll_fd < MAX_CONNECTIONS)
      {
          if (clientFds[current_poll_fd].revents & POLLIN)
          {
              int bytesRead = read(clientFds[current_poll_fd].fd, buffer, sizeof(buffer) - 1);

              buffer[bytesRead] = '\0';

              if (strlen(buffer) == 0)
              {
                close(clientFds[current_poll_fd].fd);
                fprintf(stdout, "[clientFds_index: %d, fd: %d]: DISCONNECTED\n"), current_poll_fd, clientFds[current_poll_fd].fd;
                clientFds[current_poll_fd] = clientFds[numberClients - 1];
                numberClients--;
                continue;
              }
              else
              {
                fprintf(stdout, "[clientFds_index: %d, fd: %d]: %s\n", current_poll_fd, clientFds[current_poll_fd].fd, buffer);
              }
              return_events -= 1;
          }
          current_poll_fd++;
      }
  }
}
