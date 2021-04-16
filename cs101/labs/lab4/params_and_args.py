import random

def flip(optional1, optional2):
    li = [optional1, optional2]
    result = random.choice(li)
    print(result)
flip('white', 'black')
flip('wide', 'narrow')
flip('clear', 'blurry')
