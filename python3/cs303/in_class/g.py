'''
incidence matrix
number of rows is the number of vertices
colums correspond to edges
'''
incid = [
            #e  e  e  e     colums correspond to edges
            #0  1  2  3
            [1, 1, 1, 1],   #v0     1 means the vertex and edge touch
            [0, 0, 1, 1],   #v1     rows correspond to vertices
            [1, 0, 0, 0]    #v2
        ]
#Adjacency matrix
adj = [
        #v  v  v
        #0  1  2
        [1, 2, 1],  #v0     1 means there is a edge that connects the pair of vertices
        [2, 0, 0],  #v1     2 means there are two edges that connect v0, v1
        [1, 0, 0]   #v2
      ]

#incid[i] is the list corresponding to row i
print(incid[0])
print(incid[1])
#vertex v1, e2
print(incid[1][2])
#given the incid, build the adj

print('number of vertices =', len(incid))
#make the Adjacency matrix from the incid matrix
