li = [923, 13, 39, 45, 87, 1903]
print(li[-2])
print(li[-1])
print(li[-4])
print(li[-6])
#print(li[-7])
print('----------------------')

print(li[2:])
print(li[2:5])
print(li[2:(len(li) - 1)])
print(li[2:(len(li))])
print(li[2:(len(li) + 1)])
print(li[2:(len(li) + 5)])
print(li[2:-2])
print(li[2:-3])
print(li[2:-4])

for i in li:
    if i > 50:
        i = 50
    print(i)

print('----------------------')
for i in range(len(li)):
    if li[i] > 50:
        li[i] = 50
    print(li[i])

print(li[0:3])

del li[2]

li = [923, 13, 39, 45, 87, 1903]
li.remove(87)
li.append(87)
li.remove(87)
li.append(87)
li.remove(87)
li.append(100)
li.append(87)

print(li)
print('----------------------------------------')

cat_name1 = ['Z', 'o', 'p', 'h', 'i', 'e']
cat_name2 = 'Zophie'
print(cat_name2[3])
print(cat_name2[4])
print(cat_name2[0])
print('----------------------------------------')

'''
if 13 in li:
    print('True')
'''
if 13 not in li:
    print(13)
else:
    print('True')

print(li)
