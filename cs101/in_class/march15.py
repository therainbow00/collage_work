''' Your function should print what you see below:
0, 2, 4, 6, 8, ---->  0, 1 * 2, 2 * 2, 2 * 3, 2 * 4
1, 3, 5, 7, 9, ---->  0 + 1, 2 + 1, 4 + 1, 6 + 1, 8 + 1 ----> 0 + 1, (1 * 2) + 1, (2 * 2) + 1, (3 * 2) + 1, (4*2) + 1
0, 2, 4, 6, 8,
1, 3, 5, 7, 9,
'''
def test():
    for row in range(4): # 0, 1, 2, 3
        string = ''
        for col in range(5): # 0, 1, 2, 3, 4
            if row % 2 == 0:
                string += str(col * 2) + ', ' # "2, "
            else:
                string += str((col * 2) + 1) + ', ' # "2, "
        print(string)
test()
