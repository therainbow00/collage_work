def sum():
    '''
    sum starting from 0 up to variable number, 10 + 11 + 12 + 13 + .... + number - 1 the length of this list is number - 10
                                                0, 1, 2, 3, ... + number - 1
    I am getting number - 1 + 10 at the end, while I wan to have number - 1
    print the list below
       -number, -number + 1, ..., 0
    [0,1,2,3,...,n]
    '''
    list_number = [913, 123, 342, 23]
    print(list_number[2])
    #Ex: print a list of number such that if each number is even add 10, if its odd add 20:

    number = int(input('Enter an integer (positive): '))

    #total = 0
    for i in range(number): # start from 0 go up to n - 1, e.g. i = 0, 1, 2, 3, 4
        #14, 12, 10, 8, 6, 4, 2, 0
        print(i)
        # in single argument range(), we only change the ending point. The start is always 0 by default.
        #even
        i = i + 10  #setting the starting point
        #odd
        i = i + 20
        '''
        print('total before update', total, i)
        total += i # total = total + i
        print('total after update ', total)
        print('i =', i)
        '''

    '''
    print('total after for', total)
    i = 0
    while i < number:
        print('i =', i)
        i += 1
    '''
sum()
