'''
*
**
***
****
*****
'''
m = 0

def print_func(n):
    print('*' * n)

def astrik(n):
    global m
    for i in range(n):
        print_func(i + 1)
        m += i
    #print(m)
    #return m
print(astrik(5))

astrik(10)
#print(n)
