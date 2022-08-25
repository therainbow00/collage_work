#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *path = "/user/bin/ls";
char *arglist[] = {
    "ls",
    "-l",
    "/u1/junk",
    0
};
int main(int argc, char *argv[], char *envp[])
{
    int rv; // return value of fork
    int status; // exit status of child

    for (int i = 0; envp[i] != 0; i++)
    {
        printf("%s\n", envp[i]);
    }
    return 0;
    rv = fork();
    if (rv == 0)
    {
        printf("I am the child, pid = %d ppid = %d\n", getpid(), getppid());
        execve(path, arglist, envp);
        printf("You should not see this line.\n");
        return 3;
    }
    else
    {
        wait(&status);
        printf("I am the parent, child pid = %d, pid = %d ppid = %d\n", rv, getpid(), getppid());
        printf("Exit status of child was %d\n", status);
    }
    return 0;
}
