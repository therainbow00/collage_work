def print_answer(answer):
    for i in range(len(answer)):
        if i == len(answer) - 1:
            print(answer[i], end = ']')
            print()
            break
        print('[', end = '')
        print(answer[i], end = ', ')

def check_target(target):
    if (target <= int (pow(-10, 9)) or target >= int (pow(10, 9))):
        print('The target is either too small or too large')
        exit(1)

def check_length(split_list):
    if (len(split_list) <= 2 or len(split_list) >= int (pow(10, 4))):
        print('The lenght is either too small or too large')
        exit(1)

def convert_to_int(split_list):
    for j in range(len(split_list)):
        split_list[j] = int (split_list[j])

num = input()
split_num = num.split(',')
target = int(input())

convert_to_int(split_num)
check_target(target)
check_length(split_num)

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

print_answer(answer)
