#!/usr/bin/env python3

from termcolor import colored, cprint

text = colored("Hello world!", "red", attrs=["blink"])
print(text)


cprint("Hello world!", "green", "on_red")
