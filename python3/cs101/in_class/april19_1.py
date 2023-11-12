dic_class = {991012390012: 'matt'}
num = 1

def assignment(name, Id):
    #global dic_class

    global num
    while True:
        Id = int(input('Please enter your ID: '))
        if len(Id) < 8:
            break
        name = input('Please enter your name: ')
        dic_class[Id] = name
        num += 1
    print('number: ', num)

Id = int(input('Please enter your ID: '))
name = input('Please enter your name: ')

assignment('matt', 991923923)
assignment('adam', 991902834)
assignment('ari', 9328491001)

print(dic_class)

assignment(name, Id)
print(dic_class)
