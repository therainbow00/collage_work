
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "commands.h"
#include "connection.h"
#include "utils.h"

#define BUFFER_SIZE  4096
#define MAX_N_TOKENS 10

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

// HELLO uniqueKey path
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

// GOODBYE uniqueKey
struct connection *processGoodbye(int argc, char *argv[], struct connection *connList) {
  if( argc != 2 ) {
    fprintf(stderr, "error: expected 'GOODBYE uniqueKey'\n");
    return connList;
  }

  char *uniqueKey = argv[1];

  struct connection *conn = conn_get(connList, uniqueKey);

  if( conn == NULL ) {
    fprintf(stderr, "error: key %s does not exist\n", uniqueKey);
    return connList;
  }

  char *message = mergeStrings(4, CMD_GOODBYE, ARGS_DELIM_STR, uniqueKey, "\n");

  writeToFd(conn->fd, message);

  free(message);
  close(conn->fd);

  connList = conn_remove(&connList, conn);

  return connList;
}

// SUM uniqueKey N1 N2 ...
void processSum(int argc, char *argv[], const struct connection *connList) {
  if( argc < 3 ) {
    fprintf(stderr, "error: expected 'SUM uniqueKey N1 [N2 N3 ... NN]'\n");
    return;
  }

  char *uniqueKey = argv[1];

  struct connection *conn = conn_get(connList, uniqueKey);

  if( conn == NULL ) {
    fprintf(stderr, "error: key '%s' does not exist.\n", uniqueKey);
    return;
  }

  int sum = 0;

  for(int i = 2; i < argc; i++) {
    sum += atoi(argv[i]);
  }

  char numberMsg[12]; // 2^32 requires 10 bytes char-encoded, \n + \0
  sprintf(numberMsg, "%d\n", sum);

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

  if( strcmp(command, CMD_HELLO) == 0  ) {
    connList = processHello(tokenIndex, tokens, connList);
  }
  else if( strcmp(command, CMD_GOODBYE) == 0 ) {
    connList = processGoodbye(tokenIndex, tokens, connList);
  }
  else if( strcmp(command, CMD_SUM) == 0 ) {
    processSum(tokenIndex, tokens, connList);
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
  printf("usage: %s <fifoPath>\n", argv[0]);
  printf("\tCtrl + C to quit\n\n");

  printf("Supports the following commands:\n");
  printf("\tHELLO uniqueKey fifoPath\n");
  printf("\t\tnote: fifoPath should be absolute or relative to server\n");
  printf("\t\ton success: sends 'HELLO uniqueKey\\n' through FIFO\n");
  printf("\t\ton failure: logs failed message to stderr\n");
  printf("\t\texample:\n");
  printf("\t\t  HELLO bob ~/A-fifos/sumFifo\n\n");
  printf("\tSUM uniqueKey number1 [number2 number3 ... numberN]\n");
  printf("\t\ton success: sends 'SUM <computedSum>\\n' through FIFO\n");
  printf("\t\ton failure: logs failed message to stderr\n");
  printf("\t\texamples:\n");
  printf("\t\t  SUM 1\n");
  printf("\t\t  SUM 1 2\n");
  printf("\t\t  SUM 9 7 999 -14\n\n");
  printf("\tGOODBYE uniqueKey\n");
  printf("\t\tnote: this will close an open connection opened with a HELLO command\n");
  printf("\t\ton success: sends 'GOODBYE uniqueKey\\n' through FIFO\n");
  printf("\t\ton failure: logs failed message to stderr\n");
  printf("\t\texample:\n");
  printf("\t\t  GOODBYE bob\n");
}

int main(int argc, char *argv[]) {
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
}
