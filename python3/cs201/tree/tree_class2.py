#!/usr/bin/env python3

class Tree:

    def __init__(self, data):
        self.data = data
        self.count = 1
        self.left = None
        self.right = None

    def search(self, data):
        print(self.data)
        if self.data == data:
            return True
        elif data < self.data:
            if self.left == None:
                return False
            else:
                return self.left.search(data)
        else:
            if self.right == None:
                return False
            else:
                return self.right.search(data)

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

    def insert(self, data):
        if self.data == data:
            self.count += 1
            return
        elif data < self.data:
            if self.left == None:
                self.left = Tree(data)
            else:
                self.left.insert(data)
        else:
            if self.right == None:
                self.right = Tree(data)
            else:
                self.right.insert(data)

if __name__ == "__main__":
    root = Tree(20)
    root.insert(10)
    root.insert(5)
    root.insert(3)
    root.insert(6)
    root.insert(12)
    root.insert(11)
    root.insert(15)
    root.insert(25)
    root.insert(23)
    root.insert(22)
    root.insert(24)
    root.insert(30)
    root.insert(28)
    root.insert(32)


    # print(root.data, root.left.data, root.right.data)
    root.print_tree()
    print("Starting BFS")
    print(root.BFS(32))
    print("Starting DFS")
    print(root.DFS(32))
    print("Starting binary search")
    print(root.search(32))
