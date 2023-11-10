/*
Read from the console.  Sample transcript...

cs202@cs:~/solutions/h9$ ./b_count.o
Starting point: 10
Ending point: 20
10
11
12
13
14
15
16
17
18
19
20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int start, end;
    printf("Starting point: ");
    scanf("%d", &start);
    printf("Ending point: ");
    scanf("%d", &end);

    for (int i = start; i <= end; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}
