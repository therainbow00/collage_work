'''
a = ['hi', 13, 321.8, True]
a.append('hello')
a += [8137]
'''

#print('Array', a)

matrix = [[2, 4, 8], [12, 74, 4], [31, 13, 9]]

print('Matrix 3x3', matrix)

queue = [1, 2, 3, 4, 5, 6, 7]

def push(q, element):
    q.append(element)
def pop(queue, n):
# [21, 44, 8, 0, 100]
    #new_queue = []
    for i in range(n):
        q = queue[0]
        new_queue = queue[1:len(queue) - 1]
        queue = new_queue
        print('poping', q)
        print(queue)
    return queue

queue = pop(queue, 2)

print('push')
push(queue, 100)
print(queue)

#Linked List ---------

#12 -> 31 -> 21938 -> 8 pointer for the last element is null
