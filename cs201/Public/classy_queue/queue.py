#!/usr/bin/env python3

class Queue:

    def __init__(self, name):
        self.name = name
        self.li = []

    def print_labeled(self):
        print(f"==== Queue ({self.name}) ==========")
        for item in self.li:
            print(item)
        print(f"==== Queue END ({self.name}) ==========")

    def add(self, item):
        self.li.append(item)

    def remove(self):
        return self.li.pop(0)

    def __len__(self):
        return len(self.li)

if __name__ == "__main__":
    print(f"Testing \"{__file__}\"...")
    bank_q = Queue("bank")
    bank_q.add("Alice")
    bank_q.add("Bob")
    print(f"REMOVED ({bank_q.name}):", bank_q.remove())
    bank_q.print_labeled()

    pizza_q = Queue("pizza")
    pizza_q.add(["Large", "pepperoni"])
    pizza_q.add(["Small", "cheese"])
    print(f"REMOVED ({pizza_q.name}):", pizza_q.remove())
    pizza_q.print_labeled()

    print(len(pizza_q))

    # print(bank_q)
    # print(type(bank_q))
    # print(type(bank_q) is Queue)
