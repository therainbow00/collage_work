
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "src/sum-server/commands.h"
#include "src/sum-server/utils.h"

int main(int argc, char *argv[]) {
    if (argc < 2) 
    {
        printf("usage: %s <server-fifo> <client-fifo>\n", argv[0]);
        return 0;
    }
    char *client_fifo = argv[2], *server_fifo = argv[1], string[1024];
    
    int read_fd = open(client_fifo, O_RDONLY), write_fd = open(server_fifo, O_WRONLY), bytesRead;
    if (read_fd < 0)
    {
        mkfifo(client_fifo, 0666);
        printf("Pipe created\n");
    }
    
    while (write_fd > 0)
    {
        fgets(string, strlen(string), stdin);
        write(write_fd, string, strlen(string));
        
        read(read_fd, string, strlen(string));
        printf("%s\n", string);
    }
    close(write_fd);
    close(read_fd);
    
    
    return 0;
}
