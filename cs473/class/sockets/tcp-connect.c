
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

#define PORT 57300

#define RANDOM_MSG_LENGTH 8

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

    for(;;) {
        int incomingFd = accept(listenerFd, NULL, NULL);

        if( incomingFd == -1 ) {
            perror("accept");
            break;
        }

        ssize_t bytesRead;

        // keep in mind that this means we are locked into comm w/ whatever first connects to our socket
        do {
            bytesRead = read(incomingFd, buffer, BUFSIZ - 1);

            buffer[bytesRead] = '\0';

            write(incomingFd, "echo: ", 6);
            write(incomingFd, buffer, strlen(buffer));
        } while( bytesRead > 0);

        close(incomingFd);
    }

    close(listenerFd);

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
