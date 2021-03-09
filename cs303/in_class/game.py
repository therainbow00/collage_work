#Monty Hall Game
import random
'''
lst = [0, 0, 0]
for i in range(10000):
    lst[random.randint(0, 2)] += 1
    #print(random.randint(0, 2))
print(lst)
'''

'''
The Game: 3 doors, a prize behind each door
          one good prize; two goats (bad prize)

    Prizes are set up randomly.

    Monty Hall says to consestant: Pick a door 1, 2, 3
    Contestant picks a door 1 or 2 or 3

    Monty shows the goat behind one of the doors, which is NOT
    the contestant's door.

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
for k in range(10000):
    '''
    set up the prizes
    0 means goat
    1 means fabulous prize
    '''
    for j in range(3):
        doors[j] = 0
    #put 1 behind of the three doors
    doors[random.randint(0, 2)] = 1
    #make the contestant's choice
