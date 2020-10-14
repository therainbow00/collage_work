#include <stdio.h>

#define FALSE 0
#define PI 3.14159

int main(int argc, char *argv[])
{
    char st[10];
    st[0] = 'a'; // 0101 0101
    st[1] = 't'; // ...
    st[2] = '\0'; // 0000 0000

    printf("%s\n", st);
    printf("%d\n", st[2]);
}
