
#include <stdio.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {

    if( argc < 2 ) {
        printf("usage: %s <socket-path>\n", argv[0]);
        return 0;
    }

    char *socketPath = argv[1];

    unlink(socketPath);

    struct sockaddr_un address;

    address.sun_family = AF_UNIX;
    strncpy(address.sun_path, socketPath, sizeof address.sun_path);

    int listenerFd = socket(AF_UNIX, SOCK_STREAM, 0);

    if( listenerFd == -1 ) {
        perror("socket");
        return -1;
    }

    if( bind(listenerFd, (struct sockaddr *) &address, sizeof(struct sockaddr_un)) == -1 ) {
        perror("bind");
        return -1;
    }

    if(listen(listenerFd, 10) == -1 ) {
        perror("listen");
        return -1;
    }

    char buffer[BUFSIZ];

    // signal handler.  The SIG_IGN is a constant used to ignore without explicitly
    //   attaching a signal handler
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
    unlink(socketPath);

    return 0;
}
