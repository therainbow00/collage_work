#!/usr/bin/env python3

class CompleteTree:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def insert(self, data):
        visit_queue = [self]
        while True:
            node = visit_queue.pop(0)
            if node.left == None:
                node.left = CompleteTree(data)
                return
            else:
                visit_queue.append(node.left)
            if node.right == None:
                node.right = CompleteTree(data)
                return
            else:
                visit_queue.append(node.right)

    def BFS(self, data):
        visit_queue = [self]
        while len(visit_queue):
            node = visit_queue.pop(0)
            print(node.data)
            if node.data == data:
                return True

            if node.left != None:
                visit_queue.append(node.left)
            if node.right != None:
                visit_queue.append(node.right)
        return False

    def DFS(self, data):
        print(self.data)
        if self.data == data:
            return True
        if self.left != None and self.right != None:
            return self.left.DFS(data) or self.right.DFS(data)
        elif self.left != None:
            return self.left.DFS(data)
        elif self.right != None:
            return self.right.DFS(data)
        return False

    def print_tree(self):
        if self.left != None:
            self.left.print_tree()
        print(self.data)
        if self.right != None:
            self.right.print_tree()

if __name__ == "__main__":
    root = CompleteTree(5)
    for i in range(20,60):
        root.insert(i)
    # print(root.data, root.left.data, root.right.data)
    root.print_tree()
    print("Starting BFS")
    print(root.BFS(22))
    print("Starting DFS")
    print(root.DFS(23))
