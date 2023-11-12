#Monty Hall Game
import random
'''
lst = [0, 0, 0]
for i in range(10000):
    lst[random.randint(0, 2)] += 1
    print(random.randint(0, 2))
print(lst)
'''

'''
The Game: 3 doors, a prize behind each door
          one good prize; two goats (bad prize)

    Prizes are set up randomly.

    Monty Hall says to consestant: Pick a door 1, 2, 3
    Contestant picks a door 1 or 2 or 3

    Monty shows the goat behind one of the doors, which is NOT
    the contestant's door. Pick a door that has a goat behind it
    and is NOT the contestants's choice.

    Monty says do you want to keep the door you have already picked or
          OR would you like to switch door to the left over door?
     (stick with already chosen door OR swap to the left over door)

    Your second choice is either stick with the original,
                        OR the left over door

     Monty shows whats behind the second choice door
          goat or fabulous prize

    What is the best strategy?

    It doesn't make any difference. OR

    Stick with first choice
    Switching to the left over door
'''

doors = [0, 0, 0]
stick_count = 0
switch_count = 0
for k in range(10000): #play game 10000
    '''
    set up the prizes
    0 means goat
    1 means fabulous prize
    '''
    for j in range(3): #putting in the goats
        doors[j] = 0
    #put 1 behind of the three doors
    pd = random.randint(0, 2)
    doors[pd] = 1 #storing the fabulous prize
    #make the contestant's choice
    cc = random.randint(0, 2) #contestants choice
    '''
    Monty shows a goat behind a door that is not the contestant's door
    md is Monty's bad door; md != cc  door[md] == 0
    '''
    #value for md, Monty's door
    for md in range(3):
        if md != cc and doors[md] == 0:
            break
    '''
    md =
    Monty gives the contestant a a decision: keep cc or change it.
    '''
    cn = 3 - (cc + md)
    if cc == pd:
        stick_count += 1
    if cn == pd:
        switch_count += 1
print('stick with first choice: ', stick_count)
print('switch: ', switch_count)
