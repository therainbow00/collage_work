def call(name):
    age = 25
    if name == 'Alice':
        print('Hi, Alice!')
    elif age < 12:
        print('You are not Alice, Kiddo.')
    #elif age > 20:
        #print('Hey there')
    else:
        print('You are neither Alice nor a kiddo')

        #print('Hello, Stranger!')
def weather(statement):
    hours = 0
    while statement == 'raining' and hours < 6:
        hours += 1 # hours = hours + 1    1, 2, 3, 4, 5, 6
        print('waiting...')
    print('Go outside')

call('John')
call('Alice')

var = 'raining'
weather(var)
var = 'sunny'
weather(var)
