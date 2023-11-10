#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
      perror(argv[0]);
      printf("Usage: %s <words...> (needs more arguments.)\n", argv[0]);
      return 0;
    }
    //printf("argc = %d\n", argc);

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0)
    {
        printf("This program delets a single directory at a time, wiht or with out contents.\n"
               "Sucessful run: program <argument1/directory>\n");
        return 0;
    }

    if (remove(argv[1]) < 0)
    {
        perror("removed directory failed\n");
        return -1;
    }
    else
    {
        return 0;
    }
}
