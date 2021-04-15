'''
var = input("Enter your name: ")
counter = 0
while var != 'Alice' and counter < 3:
    print("Permission denied!")
    var = input("Try again: ")
    counter += 1
print("logging in ...")
print(type(name))
########################################
name = ""
while name != 'your name':
    name = input("Enter your name: ")
print("Thank you!")
#######################################
name = input("Enter a name: ")
'''
while True:
    name = input("Enter a name: ")
    if name == 'Alice':
        print('Hi Alice!')
        break
    elif name == 'John':
        print("Hi John!")
        break
    else:
        print("Try again: ")
        continue
print("Thank you!")
