import random
import pprint

# writting a simple tic tac toe
tic_tac_toe = {'TL': 0, 'TC': 0, 'TR': 0,
               'LC': 0, 'CC': 0, 'RC': 0,
               'BL': 0, 'BC': 0, 'BR': 0}

TTT = list(tic_tac_toe.keys())
print(TTT)
turn = 0

def print_board():
    for row in range(3):
        for col in range(3):
            if tic_tac_toe[TTT[(row * 3) + col]] == 1:
                #'| {0} | {1} | {2} |'.format()
                print('   | ' * col + ' x ' + '   | ' * (2 - col))
                print('-------------------------------------------')
            elif tic_tac_toe[TTT[(row * 3) + col]] == 2:
                print('   | ' * col + ' o ' + '   | ' * (2 - col))
                print('-------------------------------------------')
            else:
                print('   | ' * col + '   ' + '   | ' * (2 - col))
                print('-------------------------------------------')

while 0 in tic_tac_toe.values():
    if turn % 2 == 0:
        user = int(input('Enter a number: '))
        if user < 9:
            if tic_tac_toe[TTT[user]] == 0:
                tic_tac_toe[TTT[user]] = 1
                turn += 1
                print_board()
            else:
                print('The place is not avilable!')
                continue
        else:
            print('The number was invalid!')
            continue
    else:
        com = random.randint(0, 8)
        if tic_tac_toe[TTT[com]] == 0:
            tic_tac_toe[TTT[com]] = 2
            turn += 1
            print_board()
        else:
            continue
        #print(TTT[user])
pprint.pprint(tic_tac_toe)
