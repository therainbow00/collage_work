def sum():
    # sum starting from 0 up to variable number, 10 + 11 + 12 + 13 + .... + number - 1 the length of this list is number - 10
    #                                            0, 1, 2, 3, ... + number - 1
    #I am getting number - 1 + 10 at the end, while I wan to have number - 1
    number = int(input('Enter an integer: '))
    total = 0
    for i in range(number - 10): # start from 0 go up to n - 1, e.g. i = 0, 1, 2, 3, 4
        # in single argument range(), we only change the ending point. The start is always 0 by default.
        i = i + 10  #setting the starting point
        print('total before update', total, i)
        total += i # total = total + i
        print('total after update ', total)
        #print('i =', i)

    print('total after for', total)
    #i = 0
    #while i < number:
    #    print('i =', i)
    #    i += 1
sum()
