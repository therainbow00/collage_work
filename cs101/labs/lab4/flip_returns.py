import random

def flip(optional1, optional2):
    li = [optional1, optional2]
    result = random.choice(li)
    return result
result1 = flip('white', 'black')
result2 = flip('clear', 'dark')

print(f'The color {result1} is {result2}!')
