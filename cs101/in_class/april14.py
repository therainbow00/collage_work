var = 'hello'
#var.append(', world!')
var += ', world!'
print(id(var))
var = 'hello'
print(id(var))

print('--------------------------------')

#import copy
def modification(some_input):
    #list = copy.copy(some_input)
    some_input += ['CS101']

list = [1, 2, 43, 20]
print(list)
print('old id', id(list))
modification(list)
print('new list', list)
print('new id', id(list))
