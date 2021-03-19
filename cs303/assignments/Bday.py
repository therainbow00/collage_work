
import random
num_parties = 1000

pz = int(input('Enter party size: '))
count = 0 #number of parties that have 2 people with same bday
for i in range(num_parties):
    party = []
    for j in range(pz):
        bday = random.randint(1, 365)
        '''
        print('bday: ' + str(bday))
        print('first print: ' + str(party))
        '''
        if len(party) == 0:
            party.append(bday)
        else:
            for k in range(len(party)):
                #print('after append: ' + str(party))
                if bday == party[k]:
                    count += 1
            if count == 0:
                party.append(bday)

        #print('element in party: ' + str(party[j]))
        print('count: ' + str(count))
        #print('second print: ' + str(party))

        '''
        if its already in the list than make count one large
        otherwise add it to the list
        '''
print(count / num_parties)
