dic = {'1': 'matt', '2': 'adam', 3: 'rose'}
print(dic[3])
print(dic['2'])
dic['4'] = 139
print(dic)
print(dic.keys())
print(dic.values())
for i in dic:
    print(i)
print('---------------------------')
for key in dic.keys():
    print(key, dic[key])
print('---------------------------')
for item in dic.items():
    print(item)
print(type(dic.items()))
print(type(dic.keys()))
print(type(dic.values()))
