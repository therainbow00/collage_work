inch = 12.0
yd = 3.0
mi = 5280.0

feet = float(input('Enter a distance in feet: '))
print('Convert to which unit?')
unit = input('Options - '
                  'inches, '
                  'yards, '
                  'miles: ')

unit = unit.lower()
unit = unit.strip()

if unit == 'inches':
    print(feet * inch)
elif unit == 'yards':
    print(feet / yd)
elif unit == 'miles':
    print(feet / mi)
else:
    print('Invalid unit selection \'' + unit + '\'.')
