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
      perror(argv[0]);
      printf("Usage: %s <words...> (need more arguments)\n", argv[0]);
      return 0;
    }
    //printf("argc = %d\n", argc);

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0)
    {
        printf("This program lists the contents of the specified directory.\n"
               "Sucessful run: program <argument1/directory path>\n");
        return 0;
    }

    DIR *d;
    struct dirent *dp;

    d = opendir(argv[1]);

    if (d == NULL)
    {
        perror(argv[1]);
        printf("Cannot open (%s), must type full path.\n", argv[1]);
        return 1;
    }
    else
    {
        if (strcmp(argv[2], "-l") == 0)
        {
            FILE *file = popen("stat", "r");
            while ((dp = readdir(d)) != NULL)
            {
                if (strcmp(dp->d_name, "..") == 0 || strcmp(dp->d_name, ".") == 0)
                {
                    continue;
                }
                printf("%s\n", dp->d_name);
            }
        }
        else
        {
            while ((dp = readdir(d)) != NULL)
            {
                if (strcmp(dp->d_name, "..") == 0 || strcmp(dp->d_name, ".") == 0)
                {
                    continue;
                }
                printf("%s\n", dp->d_name);
            }
        }
        closedir(d);
    }
    return 0;
}
