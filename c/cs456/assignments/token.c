#include <stdio.h>

FILE *fp = fopen("file.txt", 'r');
FILE *pro = fopen("program.txt", 'r');

char* read_next_token()
{
    char str2[100];
    int i = 0;
    int flag = 0;
    while (!flag)
    {
        fscanf(pro, "%c", &str2[i])
        if (str2[i] == ' ')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }

        else if (str2[i] == '\n')
        {
            i = 0;
            continue; // go to the beginning of the while
        }

        else if ( str2[i] == '(')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }

        else if ( str2[i] == ')')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }

        else if ( str2[i] == ';')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }

        else if ( str2[i] == '=')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }

        else if ( str2[i] == '+')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }

        else if ( str2[i] == '{')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }

        else if ( str2[i] == '}')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }

        else if ( str2[i] == '<')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }
        else if ( str2[i] == '>')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }
        else if ( str2[i] == '/')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }
        else if ( str2[i] == '*')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }
        else if ( str2[i] == '%')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }
        else if ( str2[i] == '"')
        {
            str2[i] = '\0';
            if (strlen(str2))
            {
                return str2;
            }
        }
        i++;
    }
}

int main() {

    struct tuples{
        int state;
        char token[20];
        char stack[20];
        int next_state;
        char next_stack[20];
        char move;
    }
    tuples all_tuples[200];


    int i = 0;
    while(fp != EOF ){
        fscanf(fp, "%d", &all_tuples[i].state);
        fscanf(fp, "%s", &all_tuples[i].token);
        fscanf(fp, "%s", &all_tuples[i].stack);
        fscanf(fp, "%d", &all_tuples[i].next_state);
        fscanf(fp, "%s", &all_tuples[i].next_stack);
        fscanf(fp, "%c", &all_tuples[i].move);
        i++

    }
    token = read_next_token();
    int current_state = 1;
    stack_top = '$';
    while(token){
        int k = 0;
        for(k=0; k < 200; k++){
            if(all_tuples[k].state == current.state && all_tuples[k].token == token && all_tuples[k].stack == stack_top){
                current_state = all_tuples[i].next_state
                stack_top = all_tuples[i].stack_next
                next_move = all_tuples[i].move
                push.stack(stack.top);
                if(move == 'R'){
                    token = read_next_token();
                }
            }

        }
    }



}
