'''
a * (b + c) == (a * b) + (a * c)
check the distributive law for mod 5 arithmetic
'''
for a in range(5):
    for b in range(5):
        for c in range(5):
            bpc = (b + c) % 5
            lhs = (a * (b + c)) % 5
            atb = (a * b) % 5
            atc = (a * c) % 5
            rhs = (atb + atc) %5
            if lhs != rhs:
                print('Distributive law fails!')
print('done')
