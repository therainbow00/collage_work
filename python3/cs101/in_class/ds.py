'''
array
a = ['hi', 13, 321.8, True]
a.append('hello')
a += [8137]
'''

#print('Array', a)
#matrix
matrix = [[2, 4, 8], [12, 74, 4], [31, 13, 9]]

print('Matrix 3x3', matrix)

#queue
#first in, first out = fifo
queue = [1, 2, 3, 4, 5, 6, 7]

def push(q, element):
    q.append(element)
    print(q)
def pop(queue, n):
# [21, 44, 8, 0, 100]
    new_queue = []
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
'''
Linked List ---------
|13/8|20/8| 8/70|
value/next

13 -> 8 -> 70 -> 100 -> 52 ->  pointer for the last element is null
<- 13 -> <- 20 -> <- 8 -> <- 70 -> <- 100 -> <- 52 ->

null/13/20|13/20/8|20/8/70|8/70/100| ...
previous/value/next
'''
'''
tree - binary tree ----------
               13
            /     \
         20           8
       /   \         /
     70     100    52
13 - 20 - 8 | 8 - 70 - 100 | 20 - 52
[13, 20, 8, 70, 100, 52]
'''
'''
stack --------
last in first out = lifo
push to the end  (top of the stack)
pop from the end (top of the stack)

|52  |
|100 |
|70  |
|8   |
|20  |
|13  |
'''
