#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
void check_target(int list[])
{

}
*/
int main (int argc, char *argv[])
{
    char num[1000], split_num[1000], *token;
    int target, split_num_int[1000];
    scanf("%s", num);

    token = strtok(num, ",");
    scanf("%d", &target);

    int i = 0;
    while (token != NULL)
    {
        split_num_int[i] = atoi(token);
        //printf("%d\n", split_num_int[i]);
        token = strtok(NULL, ",");
        i += 1;
    }

    if ((target <= (int) (pow(-10, 9))) || (target >= (int) (pow(10, 9))))
    {
        printf("The target is either too small or too large\n");
        exit(1);
    }

    int size = (sizeof(split_num_int) / sizeof(split_num_int[0]));
    if ((size <= 2) || (size >= (int) (pow(10, 4))))
    {
        printf("The lenght is either too small or too large\n");
        exit(1);
    }

    int answer[1000], test = 0, size_answer = (sizeof(answer) / sizeof(answer[0]));
    for (int i = 0; i < size_answer; i++)
    {
        answer[i] = 0;
        //printf("%d\n", answer[i]);
    }

    for (int i = 0; split_num_int[i] != '\0'; i++)
    {
        for (int j = 0; split_num_int[j] != '\0'; j++)
        {
            //printf("after j loop\n");
            //printf("((split_num_int[%d]: %d != split_num_int[%d]: %d) && (split_num_int[%d]: %d + split_num_int[%d]: %d == target: %d))\n", i, split_num_int[i], j, split_num_int[j], i, split_num_int[i], j, split_num_int[j], target);
            if ((split_num_int[i] != split_num_int[j]) && (split_num_int[i] + split_num_int[j] == target))
            {
                //printf("after if statement\n");
                answer[0] = i;
                answer[1] = j;
                //printf("answer[%d]: %d, answer[%d]: %d\n", count, i, count + 1, j);
                test = 1;
                break;
            }
        }
        if (test == 1)
        {
            break;
        }
    }

    for (int i = 0; i < size_answer; i++)
    {
        if (answer[i] == '\0')
        {
            printf("]\n");
            break;
        }
        else if ((i != 0) && (answer[i + 1] == '\0'))
        {
            printf("%d", answer[i]);
        }
        else if (i != 0)
        {
            printf("%d, ", answer[i]);
        }
        else
        {
            printf("[%d, ", answer[i]);
        }
    }

}
/*
def check_target(target):
    if (target <= int (pow(-10, 9)) or target >= int (pow(10, 9))):
        print('The target is either too small or too large')
        exit(1)

def check_length(split_list):
    if (len(split_list) <= 2 or len(split_list) >= int (pow(10, 4))):
        print('The lenght is either too small or too large')
        exit(1)

num = input()
split_num = num.split(',')
target = int(input())

for j in range(len(split_num)):
    split_num[j] = int (split_num[j])

check_length(split_num)
check_target(target)

test = False
answer = []

for k in range(len(split_num)):
    for l in range(len(split_num)):
        if ((split_num[k] != split_num[l]) and (split_num[k] + split_num[l])) == target:
            answer.append(k)
            answer.append(l)
            test = True
            break
    if test == True:
        break

for i in range(len(answer)):
    if i == len(answer) - 1:
        print(answer[i], end = ']')
        print('\n')
        break
    print('[', end = '')
    print(answer[i], end = ', ')
*/
