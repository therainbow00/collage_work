#!/usr/bin/env python3

import Person
import Dog
import Cat


li = [Person.Person("Alice"), Cat.Cat(), Dog.Dog())]

random.shuffle(li)

for animal in li:
    if animal.kind == "human":
        animal.say_hello()
    elif aimal.kind == "dog":
        animal.bark()
    elif animal.kind == "cat":
        animal.meow()
