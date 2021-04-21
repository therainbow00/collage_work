import random

# writting a simple tic tac toe
tic_tac_toe = {'TL': 0, 'TC': 0, 'TR': 0,
               'LC': 0, 'CC': 0, 'RC': 0,
               'BL': 0, 'BC': 0, 'BR': 0}

TTT = list(tic_tac_toe.keys())
print(TTT)
turn = 0

while 0 in tic_tac_toe.values():
    if turn % 2 == 0:
        user = int(input('Enter a number less than 9: '))
        if tic_tac_toe[TTT[user]] == 0:
            tic_tac_toe[TTT[user]] = 1
            turn += 1
            print(tic_tac_toe)
        else:
            user = int(input('The place is not available, Enter a new number less than 9: '))
    else:
        com = random.randint(0, 9)
        if tic_tac_toe[TTT[com]] == 0:
            tic_tac_toe[TTT[com]] = 1
            turn += 1
            print(tic_tac_toe)
        else:
            continue
        #print(TTT[user])
print(tic_tac_toe)
