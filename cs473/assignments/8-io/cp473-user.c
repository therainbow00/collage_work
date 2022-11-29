/*
Write a C program named cp473.c to copy a file from 1 location to 1 or more locations. It must conform to the following specification:

cp473 <src> <dest> [<dest2> <dest3> ...]

For all input / output functions, you MUST use the system call variants. (ie read,write instead of fread,fwrite)
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>

#define BUFFSIZ     1024

int main(int argc, char *argv[]) {

  if( argc < 3 ) {
    printf("usage: %s <src-file> <dest-file> [<dest-file2> <dest-file3> ...]\n", argv[0]);
    return -1;
  }
  
  for (int dest = 2; dest < argc; dest++) 
  {
      char *destination = argv[dest];
      char buffer[BUFFSIZ];
      
      // Open the src file for reading, truncate the file if it already exists
      int read_fd = open(argv[1], O_RDONLY), write_fd = open(destination, O_CREAT | O_TRUNC | O_RDWR);
      
      if (read_fd < 0)
      {
          printf("Error opening: %s\n", argv[1]);
          return -1;
      }
      else printf("Opened: %s\n", argv[1]);
      
      if (write_fd < 0)
      {
          printf("Error opening: %s\n", destination);
          return -1;
      }
      else printf("Opened: %s\n", destination);
      
      // while there are no more bytes to read (ie read(...) == 0 )
      int bytesRead;
      
      while((bytesRead = read(read_fd, buffer, BUFFSIZ)) > 0) {
          //bytesRead = read(read_fd, buffer, BUFFSIZ);
          
          // write the output to the file you're considering
          write(write_fd, buffer, bytesRead);
          
          if (bytesRead < 0)
          {
              printf("file contents not coppied\n");
              return -1;
          }
          else printf("file contents coppied\n");
      }
      
      close(read_fd);
      close(write_fd);
      chmod(destination, S_IRWXU | S_IRGRP | S_IWGRP | S_IRWXO);
  }
  return 0;
  
}
