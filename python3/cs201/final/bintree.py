#!/usr/bin/env python3

import math
import sys

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None
        self.length = 0


    def __len__(self):
        return self.length


    def get_node(self, index):
        if index < 0 or index >= len(self):
            raise IndexError("Index out of range.")

        i = 0
        visit_queue = [self.root]
        current_node = visit_queue.pop(0)

        while i < index:
            if current_node.left:
                visit_queue.append(current_node.left)
            if current_node.right:
                visit_queue.append(current_node.right)
            current_node = visit_queue.pop(0)
            i += 1

        return current_node


    def get_value(self, index):
        return self.get_node(index).value


    def insert(self, value):
        new_node = Node(value)

        if len(self) == 0:
            self.root = new_node
            self.length += 1
            return

        i = 0
        visit_queue = [self.root]
        current_node = visit_queue.pop(0)

        while i < len(self):
            if current_node.left != None:
                visit_queue.append(current_node.left)
            else:
                current_node.left = new_node
                self.length += 1
                return
            if current_node.right != None:
                visit_queue.append(current_node.right)
            else:
                current_node.right = new_node
                self.length += 1
                return

            current_node = visit_queue.pop(0)
            i += 1
        return

    def breadth_first_traversal(self):
        traversal = []
        visit = [self.root]
        while len(visit) > 0:
            node = visit.pop(0)
            traversal.append(node.value)
            if node.left != None:
                visit.append(node.left)
            if node.right != None:
                visit.append(node.right)
        return traversal


    def _dft_visit(current_node, traversal, order_type):
        if current_node == None:
            return

        if order_type == "preorder":
            traversal.append(current_node.value)

        Tree._dft_visit(current_node.left, traversal, order_type)

        if order_type == "inorder":
            traversal.append(current_node.value)

        Tree._dft_visit(current_node.right, traversal, order_type)

        if order_type == "postorder":
            traversal.append(current_node.value)



    def depth_first_preorder_traversal(self):
        traversal = []
        Tree._dft_visit(self.root, traversal, "preorder")
        return traversal


    def depth_first_inorder_traversal(self):
        traversal = []
        Tree._dft_visit(self.root, traversal, "inorder")
        return traversal


    def depth_first_postorder_traversal(self):
        traversal = []
        Tree._dft_visit(self.root, traversal, "postorder")
        return traversal


    def breadth_first_search_node(self, search_value):
        pass


    def _dfs_visit(current_node, search_value):
        if current_node == None:
            return None

        if search_value == current_node.value:
            return current_node
        else:
            found_node = Tree._dfs_visit(current_node.left, search_value)
            if found_node != None:
                return found_node
            else:
                found_node = Tree._dfs_visit(current_node.right, search_value)
                if found_node != None:
                    return found_node


    def depth_first_search_node(self, search_value):
        Tree._dfs_visit(self.root, search_value)


    def _tree_print_recursion(self, level = 0, index = 0, width = 80):
        num_on_level = 2 ** level
        term_i = 0
        for i in range(num_on_level):
            val = self.get_value(index)
            pos = (i + 1) * (width / (num_on_level + 1))
            glyph = "(" + str(val) + ")"
            multiplier = math.floor(pos - term_i - len(glyph) / 2)
            term_i += multiplier + len(glyph)
            padding = " " * multiplier
            print(padding + glyph, end = "")
            index += 1
            if index >= len(self):
                break
        print()
        print("-" * width)
        if index <  len(self):
            self._tree_print_recursion(level + 1, index, width)


    def tree_print(self, width = 80):
        print("=" * width)
        self._tree_print_recursion(0, 0, width)


if __name__ == "__main__":

    t = Tree()

    if "value" not in dir(Node("test")):
        print("Complete the Node class to continue testing.")
        sys.exit(0)


    ascii_a_ordinal = 97
    number_nodes = 15
    for i in range(ascii_a_ordinal, ascii_a_ordinal + number_nodes):
        t.insert(chr(i))

    t.tree_print()

    print("Breadth First Traversal:")
    print(t.breadth_first_traversal())
    print("Depth First Preorder Traversal:")
    print(t.depth_first_preorder_traversal())
    print("Depth First Inorder Traversal:")
    print(t.depth_first_inorder_traversal())
    print("Depth First Postorder Traversal:")
    print(t.depth_first_postorder_traversal())
    print()

    print('Breadth First Search for "f":')
    n = t.breadth_first_search_node("f")
    if n != None:
        print(n.value, "Found!")
    else:
        print("Not found.")

    print('Depth First Search for "g":')
    n = t.depth_first_search_node("g")
    if n != None:
        print(n.value, "Found!")
    else:
        print("Not found.")
