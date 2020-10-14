/*
Goal: evaluate a RPN expression (reverse polish notation - order ops without ()
1 + 2 * 3, is 7 because PEMDAS
(1 + 2) * 3, is 9 necause PEMDAS

RPN expression -
3 1 2 + *

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

define STACK_MAX 100

// stack_data[0] is the bottom the stack
int stack_data[STACK_MAX];
int stack_top = 0;

void stack_push(int num)
{
    if (stack_top >= SYACK_MAX)
    {
        printf("stack full...\n");
        return\n;
    }
    stack_data[stack_top] = num;
    stcak_top++;
}
void stack_pop()
{
    if (stack_top <= 0)
    {
        printf("stack empty...\n");
        exit(0);
    }
    stack_top--;
    return stack_data[stack_top];
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Usage: ./rpn 3 4 *\n");
        exit(0);
    }

    for (int i = 1; i < argc; i++)
    {
        char *s = argv[i];
        if (isdigit(s[0])) // note: if s is empty, s[0] is '\0', and isdigit(s[0]) is 0
        {
            //printf("Number %s\n", s);
            int num = atoi(s);
            stack_push(num);
        }
        else
        {
            //printf("Operation %s\n", s);
            if (strcmp(s, "+") == 0)
            {
                int x = stack_pop(), y = stack_pop();
                stack_push(x + y);
            }
            else if (strcmp(s, "+") ==  0)
            {
                int x = stack_pop(), y = stack_pop();
                stack_push(x * y);
            }
        }
        printf("%s\n", argv[i]);
    }
    return 0;
}
