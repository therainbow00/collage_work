#!/usr/bin/env python3

queues = {}

def new_queue(name):
    if name in queues.keys():
        print(f"Queue name \"{name}\" already in use.")
        return
    queues[name] = []



def add(qname, item):
    queue = queues[qname]
    queue.append(item)

def remove(qname):
    queue = queues[qname]
    if length(qname):
        return queue.pop(0)

def length(qname):
    queue = queues[qname]
    return len(queue)

def print_queue(qname):
    queue = queues[qname]
    print(f"==== Queue ({qname}) ========")
    for item in queue:
        print(item)
    print("===================")

if __name__ == "__main__":
    new_queue("bank")

    new_queue("pizza")

    add("pizza", ["Large", "pepperoni"])
    add("pizza", ["Small", "cheese"])

    add("bank", "Alice")
    add("bank", "Bob")
    add("bank", "Carl")

    print_queue("bank")
    print(remove("bank"))
    # add("pizza",

    print_queue("bank")
    print(remove("bank"))
    print_queue("bank")
    print(remove("bank"))
    print_queue("bank")
    print(remove("bank"))
