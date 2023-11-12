number1 = int(input('Enter an integer: '))
number2 = int(input('Enter another integer: '))

op = input('Choose an operation (+. *. -. /): ')
result = 0

if op == '+':
    result = number1 + number2
elif op == '*':
    result = number1 * number2
elif op == '-':
    if number1 >= number2:
        result = number1 - number2
    else:
        exit()
elif op == '/':
    result = number1 / number2
else:
    print('The operation is not defined!')

print('result:', result)
