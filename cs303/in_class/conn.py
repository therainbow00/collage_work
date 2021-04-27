adj = [
        [0, 0, 0, 1, 1, 0, 0],
        [0, 0, 1, 0, 0, 1, 0],
        [0, 1, 0, 0, 0, 0, 1],
        [1, 0, 0, 0, 1, 0, 0],
        [1, 0, 0, 1, 0, 0, 0],
        [0, 1, 0, 0, 0, 0, 1],
        [0, 0, 1, 0, 0, 1, 0]
      ]
'''
is the graph connected?
breadth first search:
    pick a start vertex
        put the start vertex into queue (it is waiting to be processed)
            (add vertices at one end; remove vertices from the other end)
            <--[        ]<--
            append to add new items from the right
            popleft to remove items from the left
        repeat:
            remove a vertex; process it.
                look at the neighboors of the vertex;
                    if they have NOT been processed already add them to the queue
        process the start vertex
'''
from collections import deque
queue = deque() #vertices left to be processed
lst = [] #already processed
size = len(adj)

start = int(input('Enter an integer 0 - '+ str(size - 1) +'> '))
queue.append(start) #new vertices that need to be processed
'''                 processing a vertex, V: finding all the vertices
                                            that are connected to V by an edge
                                            an edge are not already in the queue
                                            or have not already been processed'''
lst.append(start)
while queue:
    #get the vertex to be processed
    x = queue.popleft()
    #process the vertex just removed
    for i in range(len(adj)):
        y = adj[x][i]
        if y:
            if i not in queue and i not in lst:
                queue.append(i)
                lst.append(i)
print(lst)
