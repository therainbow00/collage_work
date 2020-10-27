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
    
  return 0;
}
