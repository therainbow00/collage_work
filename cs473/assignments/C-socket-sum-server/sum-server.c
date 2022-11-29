
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <poll.h>

#include "commands.h"
#include "connection.h"
#include "utils.h"
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE     40960
#define MAX_N_TOKENS    10
#define MAX_CONNECTIONS 1024
#define PORT_NUMBER     47304

int getOrRefreshFifo(const char *fifoPath, FILE **fifo) {

  // if NULL, we haven't got one yet
  if( *fifo == NULL ) {
    mode_t prevMask = umask(000);

    if( mkfifo(fifoPath, 0666) == -1 && errno != EEXIST ) {
      perror("mkfifo");
      umask(prevMask);
      return -1;
    }

    umask(prevMask);

    *fifo = fopen(fifoPath, "r");

    return 0;
  }

  FILE *oldFifo = *fifo;

  *fifo = fopen(fifoPath, "r");

  fclose(oldFifo);

  return 0;
}

int writeToFd(int fd, const char *message) {
  int len = strlen(message);
  int totalBytesWritten = 0;

  do {
    int bytesWritten = write(fd, message + totalBytesWritten, len - totalBytesWritten);

    if( bytesWritten == -1 ) {
      perror("writeToFd|write");
      return -1;
    }

    totalBytesWritten += bytesWritten;
  } while(totalBytesWritten < len);

  return 0;
}

// HELLO uniqueKey
struct connection *processHello(int argc, char *argv[], struct connection *connList) {
  if( argc != 3 ) {
    fprintf(stderr, "error: expected 'HELLO uniqueKey path'\n");
    return connList;
  }

  char *uniqueKey = argv[1];
  char *path = argv[2];

  struct connection *existingKey = conn_get(connList, uniqueKey);

  if( existingKey != NULL ) {
    fprintf(stderr, "error: key '%s' already exists\n", uniqueKey);
    return connList;
  }

  int newConnFd = open(path, O_WRONLY);

  if( newConnFd == -1 ) {
    perror("processHello|open");
    fprintf(stderr,"unable to open %s\n for writing", path);
    return connList;
  }

  struct connection *newConn = conn_create(uniqueKey, newConnFd);

  connList = conn_insert(&connList, newConn);

  char *returnMsg = mergeStrings(4, CMD_HELLO, " ", uniqueKey, "\n");

  writeToFd(newConn->fd, returnMsg);

  free(returnMsg);

  return connList;
}

// GOODBYE
struct connection *processGoodbye(int argc, char *argv[], struct connection *connList) {
  if( argc != 2 ) {
    fprintf(stderr, "error: expected 'GOODBYE'\n");
    return connList;
  }

  char *uniqueKey = argv[1];

  struct connection *conn = conn_get(connList, uniqueKey);

  if( conn == NULL ) {
    fprintf(stderr, "error: key %s does not exist\n", uniqueKey);
    return connList;
  }

  char *message = mergeStrings(4, CMD_GOODBYE, ARGS_DELIM_STR, "\n");

  writeToFd(conn->fd, message);

  free(message);
  close(conn->fd);

  connList = conn_remove(&connList, conn);

  return connList;
}

// SUM uniqueKey N1 N2 ...
void processSum(int argc, char *argv[], struct connection *connList) {
  if( argc < 3 ) {
    fprintf(stderr, "error: expected 'SUM uniqueKey [variable-name] N1 [N2 N3 ... NN]'\n");
    return;
  }
  
  char *uniqueKey = argv[1];
  char *variable_name = argv[2];

  struct connection *conn = conn_get(connList, uniqueKey);

  if( conn == NULL ) {
    fprintf(stderr, "error: key '%s' does not exist.\n", uniqueKey);
    return;
  }

  int sum = 0;

  for(int i = 2; i < argc; i++) {
    sum += atoi(argv[i]);
  }
  //variable_name = sum;

  char numberMsg[100]; // 2^32 requires 10 bytes char-encoded, \n + \0
  sprintf(numberMsg, "%d\n", sum);
  sprintf(numberMsg, "STORED-VALUE %d\n", sum);
  
  writeToFd(conn->fd, numberMsg);
}

struct connection *processMessage(char *message, struct connection *connList) {
  char *tokens[MAX_N_TOKENS] = {"NOOP"};
  int tokenIndex = 0;

  char *messageCopy = malloc(strlen(message) * sizeof(char) + 1);
  messageCopy = strcpy(messageCopy, message);
  char delims[3];
  sprintf(delims, "%c\n", ARGS_DELIM_CHAR);

  char *token = strtok(messageCopy, delims);

  while( token != NULL ) {
    tokens[tokenIndex++] = token;

    token = strtok(NULL, delims);
  }

  char *command = tokens[0];
  
  // TODO: update processHello to handle revised format
  if( strcmp(command, CMD_HELLO) == 0  ) {
    connList = processHello(tokenIndex, tokens, connList);
  }
  // TODO: update processGoodbye to handle revised format
  else if( strcmp(command, CMD_GOODBYE) == 0 ) {
    connList = processGoodbye(tokenIndex, tokens, connList);
  }
  // TODO: update processSum to handle optional variable
  else if( strcmp(command, CMD_SUM) == 0 ) {
    processSum(tokenIndex, tokens, connList);
  }
  // TODO: handle new STORED_VALUE command
  else if( strcmp(command, CMD_STORED_VALUE) == 0 ) {
    ;
  }
  else if( strcmp(command, CMD_NOOP) == 0 ) {
    printf("NOOP is technically not an error");
  }
  else {
    fprintf(stderr, "Invalid command %s\n", command);
  }

  free(messageCopy);

  return connList;
}

void usage(int argc, char *argv[]) {
  printf("usage: %s <port-number>\n", argv[0]);
  printf("\tCtrl + C to quit\n\n");

  printf("Supports the following commands:\n");
  printf("\tHELLO uniqueKey\n");
  printf("\t\ton success: sends 'HELLO uniqueKey\\n' through socket\n");
  printf("\t\ton failure: sends error: message through socket\n");
  printf("\t\texample:\n");
  printf("\t\t  HELLO bob\n\n");
  printf("\tSUM [variable-name] number1 [number2 number3 ... numberN]\n");
  printf("\t\ton success: sends 'SUM <computedSum>\\n' through socket\n");
  printf("\t\t            if variable-name is present, stores value on a per-client basis.\n");
  printf("\t\ton failure: sends error: message through socket\n");
  printf("\t\texamples:\n");
  printf("\t\t  SUM one 1\n");
  printf("\t\t  SUM one+two 1 2\n");
  printf("\t\t  SUM 9 7 999 -14\n\n");
  printf("\tSTORED-VALUE variable-name\n");
  printf("\t\ton success: sends '<stored-sum>\\n' through socket\n");
  printf("\t\ton failure: sends error: message through socket\n");
  printf("\t\texamples:\n");
  printf("\t\t  STORED-VALUE one\n");
  printf("\t\t  STORED-VALUE one+two\n");
  printf("\tGOODBYE\n");
  printf("\t\tnote: this will close an open connection opened with a HELLO command\n");
  printf("\t\ton success: sends 'GOODBYE uniqueKey\\n' through socket\n");
  printf("\t\ton failure: sends error: message through socket\n");
  printf("\t\texample:\n");
  printf("\t\t  GOODBYE bob\n");
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

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(port);
  // TODO: initialize passive SOCK_STREAM socket on port passed in from command line
  //       hint: remember INADDR_ANY and the htons() family of functions
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0)
  {
      perror("socket_fd");
      return -1;
  }

  if ((bind(socket_fd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in))) < 0)
  {
      perror("bind");
      return -1;
  }
  
  if (listen(socket_fd, 10) < 0) 
  {
    perror("listen");
    return -1;
  }

  // TODO: update connection (declared/defined in connection.h/connection.c) to search by fd instead of key (see: conn_get)
  //       Consider extending the connection structure to store per-client variables.
  //       optional: If you want to use poll to handle waiting for writes that won't block, you could extend it to stash outgoing data as well.
  struct connection *clients; // clients linked list

  struct pollfd clientFds[MAX_CONNECTIONS];
  int numberClients = 0;

  // TODO: add passive listening socket to clientFds, increment numberClients
  
      int incoming_fd = accept(socket_fd, NULL, NULL);
      
      if (incoming_fd < 0) {
          perror("accept");
          return -1;
      }

    clientFds[0].fd = incoming_fd;
    clientFds[0].events = POLLIN;
    clientFds[0].revents = 0;

  for(;;) {

      ssize_t bytesRead;
      // TODO: use poll to listen for new connections and wait for incoming data.
      //       Optional: You would also use it to check for non-blocking writes and do the writes here if you're
      //                 updating the connection option to stash outgoing data
      //bytesRead = read(incoming_fd, buffer, BUFFER_SIZE - 1);
      int numberOfFdsWithEvents = poll(clientFds, MAX_CONNECTIONS, -1);

        if( clientFds[0].revents & ( POLLERR | POLLHUP ) ) {
          fprintf(stderr, "error on socket\n");
          break;
        }

        do {
            bytesRead = read(clientFds[0].fd, buffer, BUFSIZ - 1);

            write(clientFds[0].fd, "echo: ", 6);
            write(clientFds[0].fd, buffer, bytesRead);
        } while( bytesRead > 0);
  
      close(incoming_fd);
    }
    close(socket_fd);
}


/*int fifo_main(int argc, char *argv[]) {
  if( argc < 2 ) {
    usage(argc, argv);
    return 0;
  }

  char *fifoPath = argv[1];
  
  FILE *fifo = NULL; 

  int errorOpeningFifo = getOrRefreshFifo(fifoPath, &fifo);
  
  if( errorOpeningFifo ) {
    return -1;
  }

  struct connection *outgoingConnections = NULL;

  for(;;) {
    char buf[BUFFER_SIZE];
    
    long charsRead = fread(buf, sizeof(char), BUFFER_SIZE - 1, fifo);
    
    buf[charsRead] = 0;

    outgoingConnections = processMessage(buf, outgoingConnections);

    errorOpeningFifo = getOrRefreshFifo(fifoPath, &fifo);

    if( errorOpeningFifo ) {
      return -1;
    }
  }
}*/
