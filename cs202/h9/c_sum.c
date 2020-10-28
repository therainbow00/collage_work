/*
  Read from command-line arguments.
  Sample transcript...

cs202@cs:~/solutions/h9$ ./c_sum.o
Usage: ./c_sum.o n1 n2 n3 ...

cs202@cs:~/solutions/h9$ ./c_sum.o 3 5 8 9
25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int total = 0;
    for (int i = 1; i <= argc; i++)
    {
        if (argv[i] != NULL)
        {
            total += atoi(argv[i]);
        }
        else if (argv[1] == NULL)
        {
            printf("Usage: ./c_sum.o n1 n2 n3 ...\n");
            return 0;
        }
    }
    printf("%d\n", total);

    return 0;
}
