import random

def flip(optional1, optional2):
    li = [optional1, optional2]
    result = random.choice(li)
    return result

guess = input('Guess the result. Type either \"heads\" or \"tails\" and press ENTER:\n> ')
guess.strip().lower()

result = flip('HEADS', 'TAILS')
print(f'The coin landed on {result}!')

if guess == result:
    print('You win!')
else:
    print('You lose.')
