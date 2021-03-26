username = input('Enter name please: ')
username = username.strip()

data1 = input(username + ', Enter a word, phrase, sentence: ')
data2 = input(username + ', Enter a word, phrase, sentence: ')
data1 = data1.strip()
data2 = data2.strip()

if len(data1) > len(data2):
    print(f'{username}, I have detected that string 1 is longer.')
elif len(data2) > len(data1):
    print(f'{username}, I have detected that string 2 is longer.')
else:
    print(f'{username}, I have detected that both strings are the same length.')
