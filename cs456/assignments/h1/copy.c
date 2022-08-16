#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
      printf("Usage: %s <words...>\n", argv[0]);
      printf("Program requires a file to copy to. Example: <programname> <filename1> <filename2>.\n");
      return 0;
    }
    //printf("argc = %d\n", argc);

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
    {
        printf("This program copies contents from one file to the other."
               "This file requires 2 arguments, example: ./a.out <argument1> <argument2>.\n");
        return 0;
    }

    int fd = open(argv[1], O_RDONLY), fd_1 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC), size = 1000, r;
    char string[size];

    if (fd < 0)
    {
        perror("Opening of the file has failed\n");
        return -1;
    }
    else printf("file sucessfully opened\n");

    if (fd_1 < 0)
    {
        perror("Opening of the file 2 has failed\n");
        return -1;
    }
    else printf("file 2 sucessfully opened\n");

    while ((r = read(fd, string, size)) > 0)
    {
        write(fd_1, string, r);
        if (r > 0) printf("file contents coppied\n");
        else
        {
            printf("file contents not coppied\n");
            return -1;
        }
    }

    return 0;
}
