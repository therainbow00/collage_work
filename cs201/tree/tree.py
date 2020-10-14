#!/usr/bin/env python3

root = []


def insert(data):
    root.append(data)

def bfs(data):
    for node in range(len(root)):
        print(f"Node #{node}: {root[node]}")

        if root[node] == data:
            return True
    return False

def dfs(data):
    node = 0
    visit = [0]
    while len(visit):
        node = visit.pop(0)
        print(f"Node #{node}: {root[node]}")

        if root[node] == data:
            return True
        left_child = node * 2 + 1
        right_child = node * 2 + 2

        if right_child < len(root):
            visit.insert(0, right_child)

        if left_child < len(root):
            visit.insert(0, left_child)
    return False

if __name__ == "__main__":
    for value in range(5, 21):
        insert(value)

    print("Starting BFS search")
    print(bfs(20))
    print("Starting DFS search")
    print(dfs(20))
