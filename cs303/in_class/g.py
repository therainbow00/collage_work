#number of rows is the number of vertices
incid = [
            [1, 1, 1, 1],
            [0, 0, 1, 1],
            [1, 0, 0, 0]
        ]

adj = [
        [1, 2, 1],
        [2, 0, 0],
        [1, 0, 0]
      ]

#incid[i] is the list corresponding to row i
print(incid[0])
print(incid[1])
#vertex v1, e2
print(incid[1][2])
#given the incid, build the adj

print('number of vertices =', len(incid))
#make the Adjacency matrix from the incid matrix
