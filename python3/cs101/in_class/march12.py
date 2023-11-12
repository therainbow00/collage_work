def nested_loop():
    counter = 0
    for i in range(5): #i = 0, 1, 2, 3, 4
        print('i ', i)
    #print('done with i loop')
        for j in range(5): #j = 0, 1, 2, 3, 4
            print('j ', j)
            counter += 1
        print('done with j loop')
    print('done with i loop')
    print('counter:', counter)

def nested_while(name):
    name = ''
    while name != 'your name':
        #print('please type your name: ')
        name = input('please type your name: ')
        while name != 'john':
            name = input('please try again: ')
            print(name)
        print('hi john')
        break
nested_loop()
#nested_while('lily')
