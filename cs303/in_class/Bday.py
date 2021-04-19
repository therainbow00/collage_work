import random
num_parties = 1000

pz = int(input('Enter party size: '))
count = 0 #number of parties that have 2 people with same bday
for i in range(num_parties):
    party = []
    for j in range(pz):
        bday = random.randint(1, 365)
        if bday == party[j]:
            count += 1
        else:
            party.append(bday)
        '''
        if its already in the list than make count one large
        otherwise add it to the list
        '''
print(count / num_parties)
