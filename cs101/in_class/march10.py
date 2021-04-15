import random
'''
implementing rock, paper scissor
'''
var = random.randrange(12)

turn = 0
move = ''
while True:
    if turn % 2 == 0:
        move = input('Enter your move (r, p, s): ')
    else:
        var = random.randrange(12)
        if var < 3:
            move = 'p'
        elif var < 6:
            move = 'r'
        elif var < 9:
            move = 's'
        else:
            move = 'q'
        print('The random number is: ', var)
        print('Computer chose: ', move)
    if move == 'q':
        #turn += 1
        break
    else:
        turn += 1
        #continue
print('Game Over')
'''
print(var)
print(random.choice(range(100)))
'''

var = 10
while var > 0:
    print(var)
    var -= 1

print('--------')

for i in range(10, 0, -1):
    print(i)
