rectangular = True
has_4_sides = True

is_square = rectangular and has_4_sides

if is_square:
    print('This is a square')

rectangular = False

if is_square:
    print('Again his is a square')
