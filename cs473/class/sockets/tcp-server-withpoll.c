
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <netinet/in.h>
#include <poll.h>

#define PORT 57300

int main(int argc, char *argv[]) {

    // unix: char *socketPath = argv[1];

    // unix: unlink(socketPath);

    struct sockaddr_in address;
    struct in_addr ipAddress;

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    // IP: xxx.xxx.xxx.xxx
    // htonl(internetAddress)
    address.sin_addr.s_addr = INADDR_ANY;

    // unix: int listenerFd = socket(AF_UNIX, SOCK_STREAM, 0);
    int listenerFd = socket(AF_INET, SOCK_STREAM, 0);

    if( listenerFd == -1 ) {
        perror("socket");
        return -1;
    }

    // unix: if( bind(listenerFd, (struct sockaddr *) &address, sizeof(struct sockaddr_un)) == -1 ) {
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


            // did not check to make sure write succeeded in writing
            //  bytesRead number of byts to the socket
            write(incomingFd, "echo: ", 6);
            write(incomingFd, buffer, bytesRead);
        } while( bytesRead > 0);

        close(incomingFd);
    }

    close(listenerFd);
    //unlink(socketPath);

    return 0;
}
