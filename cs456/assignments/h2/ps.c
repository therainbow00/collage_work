#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    /*
    struct winsize ws;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	printf ("lines %d\n", ws.ws_row);
	printf ("columns %d\n", ws.ws_col);
    */
    struct dirent *read_dir;
    struct dirent *read_sub_dir;

    char file[4001], path[101];
    DIR *dir = opendir("/proc");
    if (dir == NULL)
    {
        perror("directory is empty\n");
        closedir(dir);
        return -1;
    }
    else
    {
        while ((read_dir = readdir(dir)) != NULL)
        {
            DIR *sub_dir;
            char f[101];
            if (strstr(read_dir->d_name, "1") || strstr(read_dir->d_name, "2") || strstr(read_dir->d_name, "3") || strstr(read_dir->d_name, "4") || strstr(read_dir->d_name, "5") || strstr(read_dir->d_name, "6") || strstr(read_dir->d_name, "7") || strstr(read_dir->d_name, "8") || strstr(read_dir->d_name, "9"))
            {
                remove(path);
                char path[101];

                strcpy(path, "/proc");
                strcat(path, "/");
                strcat(path, read_dir->d_name);

                sub_dir = opendir(path);

                if (sub_dir == NULL)
                {
                    perror("could not open sub directory\n");
                    closedir(sub_dir);
                    closedir(dir);
                    return -1;
                }
                else
                {
                    char target_path[11];
                    int target;

                    while ((read_sub_dir = readdir(sub_dir)) != NULL)
                    {
                        if (strcmp(read_sub_dir->d_name, "cmdline") == 0)
                        {
                            strcpy(target_path, "/proc");
                            strcat(target_path, "/");
                            strcat(target_path, read_dir->d_name);
                            strcat(target_path, "/");
                            strcat(target_path, read_sub_dir->d_name);

                            target = open(target_path, O_RDONLY);
                            if (target < 0)
                            {
                                perror("Cannot open file for reading\n");
                                closedir(sub_dir);
                                closedir(dir);
                                return -1;
                            }

                            int bytes_read = read(target, file, 4000);

                            if (bytes_read == 0)
                            {
                                strcpy(target_path, "/proc");
                                strcat(target_path, "/");
                                strcat(target_path, read_dir->d_name);
                                strcat(target_path, "/");
                                strcat(target_path, "status");

                                int target1 = open(target_path, O_RDONLY);

                                if (target1 < 0)
                                {
                                    perror("Cannot open file for reading\n");
                                    closedir(sub_dir);
                                    closedir(dir);
                                    return -1;
                                }
                                remove(file);

                                char file[4001];
                                int bytes_read_status = read(target1, file, 4000);

                                printf("%6s ", read_dir->d_name);
                                printf("[");
                                for (int i = 6; file[i] != '\n'; i++) printf("%c", file[i]);

                                printf("]");
                                printf("\n");
                                close(target1);
                                close(target);
                                continue;
                            }
                            printf("%6s ", read_dir->d_name);
                            for (int i = 0; file[i] != '\0'; i++)
                            {
                                if (file[i] == '\0') printf(" ");
                                else printf("%c", file[i]);
                            }
                            printf("\n");
                            close(target);
                        }
                    }
                }
                closedir(sub_dir);
            }
        }
        closedir(dir);
    }

    return 0;
}
