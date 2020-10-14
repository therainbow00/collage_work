#include <stdio.h>

int main(int argc, char *argv[])
{
    int ch;
    //printf("%d\n", EOF);
    while ((ch = fgetsc(stdin)) != EOF)
    {
        /*
        order of operations on that above
        check if (ch = fetc(stdin)) != -1
        to evaluate and assignment expression, do the assignment and the value of the expression is the result
        do fgetsc(stdin), '#' is returned, saved into ch, and the = thing has the value '#'
        '#' != -1
            1
            TRUE
        */
        // do something with ch, which is a character
        printf("%c", ch);
    }
    return 0;
}
