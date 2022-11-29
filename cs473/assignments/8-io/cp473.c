
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>

#define BUFSIZ     1024

int main(int argc, char *argv[]) {

  if( argc < 3 ) {
    printf("usage: %s <src-file> <dest-file> [<dest-file2> <dest-file3> ...]\n", argv[0]);
    return -1;
  }
  
  for (int dest = 2; dest < argc; dest++) 
  {
      char *destination = argv[dest];
      char buffer[BUFSIZ];
      
      int read_fd = open(argv[1], O_RDONLY), write_fd = open(destination, O_CREAT | O_TRUNC | O_RDWR), bytesRead;
      
      if (read_fd < 0)
      {
          printf("Error opening: %s\n", argv[1]);
          return -1;
      }
      else
      { 
          printf("Directory exists\n");
      }
      
      if (write_fd < 0)
      {
          printf("Error opening: %s\n", destination);
          return -1;
      }
      else
      { 
          printf("Directory exists\n");
      }
      
      while((bytesRead = read(read_fd, buffer, BUFSIZ)) > 0) {

          write(write_fd, buffer, bytesRead);
          
          if (bytesRead < 0)
          {
              perror("file contents not copied\n"); 
              return -1;
          }
      }
      
      close(read_fd);
      close(write_fd);
      chmod(destination, S_IRWXU | S_IRGRP | S_IWGRP | S_IRWXO);
  }
  return 0;
  
}
