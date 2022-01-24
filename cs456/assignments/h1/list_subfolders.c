#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
      perror("Usage: %s <words...>\n", argv[0]);
      return 0;
    }
    printf("argc = %d\n", argc);

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0)
    {
        printf("This program delets a single directory at a time, wiht or with out contents.\n"
               "Sucessful run: program <argument1/directory>\n");
    }

    DIR *d;
    struct dirent *dp;

    d = opendir(argv[1]);

    if (d == NULL)
    {
        perror("Canot open (%s)\n", argv[1]);
        return 1;
    }
    else
    {
        while ((dp = readdir(d)) != NULL)
        {
            printf("%s ", dp->d_name);
        }
        closedir(d);
    }
    return 0;
}
