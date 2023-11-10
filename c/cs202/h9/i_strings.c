/*
  Read from console.  Sample transcript...

cs202@cs:~/solutions/h9$ ./i_strings.o
Some word please (will be s1): whyohwhyohwhy
Another word (will be s2): yo
Some character: o
length of s1: 13
length of s2: 2
s2 is at position 2 of s1
first o in s1 is at index 3
s2 is at position 7 of s1

cs202@cs:~/solutions/h9$ ./i_strings.o
Some word please (will be s1): heregoesnothing
Another word (will be s2): Goes
Some character: k
length of s1: 15
length of s2: 4
No Goes in s1
No k in s1

cs202@cs:~/solutions/h9$ ./i_strings.o
Some word please (will be s1): BecauseISaidSo
Another word (will be s2): Said
Some character: b
length of s1: 14
length of s2: 4
s2 is at position 8 of s1
No b in s1

Notes
* Loop through s1
* Use strncmp(s1+i, s2)
* Before the loop set a variable to -1 to indicate haven't found s2 yet, in the loop if found set it to i.  Similarly for the character.
* After the loop check those variables to see if need to print "No ... in s1".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char s1[101], s2[101], some_char[2];
    int length_s1, length_s2, length_some_char;

    printf("Some word please (will be s1): ");
    gets(s1);
    length_s1 = strlen(s1);

    printf("Another word (will be s2): ");
    gets(s2);
    length_s2 = strlen(s2);

    printf("Some character: ");
    gets(some_char);
    length_some_char = strlen(some_char);

    printf("length of s1: %d\n", length_s1);
    printf("length of s2: %d\n", length_s2);


    int var = -1;
    int count_first = 0;
    int count = 0;
    for (int i = 0; i < length_s1; i++)
    {
        if (strncmp(s1 + i, s2, length_s2) == 0)
        {
            var = i;
            printf("s2 is at position %d of s1\n", var);
            count++;
        }
        else if (strncmp(s1 + i, some_char, length_some_char) == 0 && count_first == 0)
        {
            var = i;
            printf("first %s in s1 is at index %d\n", some_char, var);
            count_first++;
        }
    }
    for (int j = 0; j < length_s1; j++)
    {
        if (strncmp(s1 + j, some_char, length_some_char) != 0 && count == 1)
        {
            printf("No %s in s1\n", some_char);
            break;
        }
    }
    if (var == -1)
    {
        printf("No %s in s1\n", s2);
        printf("No %s in s1\n", some_char);
    }

    return 0;
}
