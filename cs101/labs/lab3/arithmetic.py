x = float(input('Enter a number: '))
y = float(input('Enter a number: '))

print("What operation would you like to perform?")
operation = input('Options - '
                  'addition, '
                  'subtraction, '
                  'multiplication, '
                  'division, '
                  'integer division, '
                  'modulus, '
                  'exponentiation: ')
operation = operation.lower()
operation = operation.strip()

if operation == 'addition':
    print('The result is ', x + y)
elif operation == 'subtraction':
    print('The result is ', x - y)
elif operation == 'multiplication':
    print('The result is ', x * y)
elif operation == 'division':
    print('The result is ', x / y)
elif operation == 'integer division':
    print('The result is ', x // y)
elif operation == 'exponentiation':
    print('The result is ', x ** y)
else:
    print('Unrecognized options \'' + operation + '\' given.')
