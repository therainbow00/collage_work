'''
starting from 2 to 14, if number is even, multiply by 2 and if not multiply by 3. At the end sum everything and return an integer
'''
def conditional_sum(end):
    total = 0
    #end = int(input('Enter your upper bound: '))
    for i in range(2, end + 1): # range(2, end + 1) == range(end + 1 - 2) == range(end - 1)
        '''
        range(end - 1)
        i = i + 2
        '''
        if i % 2 == 0:
            #print('even', i)
            total += i * 2
        else:
            #print('odd', i)
            total += i * 3
    return total

def conditional_sum2(end1):
    total = 0
    #end = int(input('Enter your upper bound: '))
    i = 2
    while i < end1 + 1: # or i <= end1
        if i % 2 == 0:
            #print('even', i)
            total += i * 2
        else:
            #print('odd', i)
            total += i * 3
        i += 1
    return total

upper_bound = int(input('Enter an upper bound: '))
#conditional_sum()
print(conditional_sum(upper_bound))
print('---------------------------conditional_sum2-----')
#conditional_sum2()
print(conditional_sum2(upper_bound))
