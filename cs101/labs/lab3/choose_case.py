animal = input('Type in the name of an animal and press ENTER: ')
print('What letter-casing would you like to use?')
casing = input('Options - '
      'upper, '
      'lower, '
      'title: ')
casing = casing.lower()
if casing == 'upper' or casing == 'Upper' or casing == 'UPPER':
    animal = animal.upper()
elif casing == 'lower' or casing == 'Lower' or casing == 'LOWER':
    animal = animal.lower()
elif casing == 'title' or casing == 'Title' or casing == 'TITLE':
    animal = animal.title()
print(animal)
