
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <time.h>
#include <poll.h>
#include <sys/resource.h>

#include "dynamic-buffer.h"

#define PORT 57300

#define RANDOM_MSG_LENGTH 8

struct pollfd createPollFd(int fd, short events) {
    return (struct pollfd) {
        .fd = fd,
        .events = events,
        .revents = 0
    };
}

unsigned getNumberAllowedFileDescriptors() {
    struct rlimit limits;

    if( getrlimit(RLIMIT_NOFILE, &limits) == -1 ) {
        perror("getrlimit");
        return 64;  // limp mode????
    }

    return limits.rlim_cur;
}

int server() {
    struct sockaddr_in address;
    struct in_addr ipAddress;

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    int listenerFd = socket(AF_INET, SOCK_STREAM, 0);

    if( listenerFd == -1 ) {
        perror("socket");
        return -1;
    }

    if( bind(listenerFd, (struct sockaddr *) &address, sizeof(struct sockaddr_in)) == -1 ) {
        perror("bind");
        return -1;
    }

    if(listen(listenerFd, 10) == -1 ) {
        perror("listen");
        return -1;
    }

    char buffer[BUFSIZ];

    sigaction(SIGPIPE, &(struct sigaction){SIG_IGN}, NULL);

    // fds and outBuffers are arrays with the same number of elements.
    // fds[n] and outBuffers[n] both contain data that is concerned with fds[n].fd
    int maxFds = getNumberAllowedFileDescriptors();
    struct pollfd *fds = malloc(sizeof(struct pollfd) * maxFds);
    struct dynamicBuffer *outBuffers = calloc(maxFds, sizeof(struct dynamicBuffer));
    int fdsLength = 0;
    // add our listener as the 0th item
    fds[fdsLength++] = createPollFd(listenerFd, POLLIN);

    for(;;) {
        int numberFdsWithEvents = poll(fds, fdsLength, -1);

        // check for and add a new connection
        if( fds[0].revents & POLLIN ) {
            numberFdsWithEvents -= 1;

            int incomingFd = accept(fds[0].fd, NULL, NULL);

            if( incomingFd == -1 ) {
                perror("accept");
            }

            fds[fdsLength++] = createPollFd(incomingFd, POLLIN);
        }

        int currFd = 1;

        // this while loop is iterating over fds in our pollfds array index 1 and above
        while(numberFdsWithEvents > 0) {

            if( fds[currFd].revents != 0 ) {
                numberFdsWithEvents -= 1;

                // Operation 1: check for errors
                // Close connection, free memory on socket hangup or error
                if( fds[currFd].revents & (POLLHUP | POLLERR) ) {
                    close(fds[currFd].fd);
                    fds[currFd] = fds[fdsLength - 1];
                    if(outBuffers[currFd].length > 0 ) {
                        free(outBuffers[currFd].data);
                    }
                    outBuffers[currFd] = outBuffers[fdsLength - 1];
                    if( outBuffers[fdsLength - 1].length > 0 ) {
                        outBuffers[fdsLength - 1].data = NULL;
                        outBuffers[fdsLength - 1].length = 0;
                    }
                    fdsLength -= 1;
                    continue;
                }

                // Operation 2: check if the socket has data ready to be read
                if( fds[currFd].revents & POLLIN ) {
                    int bytesRead = read(fds[currFd].fd, buffer, BUFSIZ);

                    if( bytesRead == -1 ) {
                        perror("read");
                    }
                    else if( bytesRead > 0 ) {
                        append(&outBuffers[currFd], buffer, bytesRead);
                        append(&outBuffers[currFd], "\n", 1);

                        fds[currFd].events |= POLLOUT;
                    } else {
                        close(fds[currFd].fd);
                        fds[currFd] = fds[fdsLength - 1];
                        if(outBuffers[currFd].length > 0 ) {
                            free(outBuffers[currFd].data);
                        }
                        outBuffers[currFd] = outBuffers[fdsLength - 1];
                        if( outBuffers[fdsLength - 1].length > 0 ) {
                            outBuffers[fdsLength - 1].data = NULL;
                            outBuffers[fdsLength - 1].length = 0;
                        }
                        fdsLength -= 1;
                    }
                }

                // Operation 3: check if the socket can be written to immediately (without blocking)
                if( fds[currFd].revents & POLLOUT ) {
                    int bytesWritten = write(fds[currFd].fd, outBuffers[currFd].data, outBuffers[currFd].length);

                    removeCharsLeft(&outBuffers[currFd], bytesWritten);

                    if( outBuffers[currFd].length == 0 ) {
                        fds[currFd].events = POLLIN;
                    }
                }

                currFd += 1;
            }
        }
    }

    close(listenerFd);
    free(fds);

    return 0;
}

void createRandomMsg(char *message, int msgLength) {
    srand(time(NULL));

    for(int i = 0; i < msgLength; i++ ) {
        message[i] = 'a' + abs(rand()) % 26;
    }
}

int client(const char *ipAddress, int port) {
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    inet_aton(ipAddress, &serverAddress.sin_addr);

    int serverFd = socket(AF_INET, SOCK_STREAM, 0);

    if(serverFd == -1 ) {
        perror("socket");
        return -1;
    }

    if( connect(serverFd, (struct sockaddr *) &serverAddress, sizeof(struct sockaddr_in) ) == -1 ) {
        perror("connect");
        return -1;
    }

    char randomMsg[RANDOM_MSG_LENGTH + 1];
    randomMsg[RANDOM_MSG_LENGTH] = '\0';

    char response[BUFSIZ];

    for(int n = 1; n <= 5; n++) {
        createRandomMsg(randomMsg, RANDOM_MSG_LENGTH);

        printf("send: %s\n", randomMsg);

        send(serverFd, randomMsg, RANDOM_MSG_LENGTH, 0);

        // real implementations shouldn't assume the entire message will be present in 1 read
        int bytesRead = read(serverFd, response, BUFSIZ - 1);
        response[bytesRead] = 0;

        printf("%s\n\n", response);

        sleep(1);
    }

    close(serverFd);
    return 0;
}

int main(int argc, char *argv[]) {

    // with no arguments, server will listen on "all interfaces" aka 0.0.0.0 aka INADDR_ANY
    if( argc == 1 ) {
        return server();
    }

    if( argc < 3 ) {
        printf("usage: %s [<ip-address> <port>]", argv[0]);
        return 0;
    }

    char *ipAddress = argv[1];
    int port = atoi(argv[2]);

    return client(ipAddress, port);
}
