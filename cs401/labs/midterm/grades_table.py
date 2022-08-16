#!/usr/bin/env python3
import re
import json
import urllib.request

with urllib.request.urlopen("https://cs.indstate.edu/~lmay1/assets/fake-grades.csv") as req:
    data = req.read().decode("utf-8")

with open("me.json", "r") as f:
    j_data = f.read()

if __name__ == "__main__":
    lines = data.split("\n")
    lines.sort()
    me = json.loads(j_data)
    a, b = me["first"][0], me["last"][0]
    pattern = re.compile(rf"^({a})[a-z]*,({b})", re.I)
    comma = 0
    sum = 0
    total = 0
    first_sum = 0
    last_sum = 0
    matches = 0
    for line in range(len(lines)):
        item = lines[line]
        if pattern.search(item):
            matches += 1
            new_item = item.split(',')
            for i in range(len(new_item)):
                if new_item[i].isalpha() and comma == 0:
                    first_sum = len(new_item[i])
                    print(new_item[i], end = ', ')
                    comma += 1
                elif new_item[i].isalpha() and comma == 1:
                    last_sum = len(new_item[i])
                    print(new_item[i], end = '')
                    comma = 0
                else:
                    f_format = float(new_item[i])
                    sum += f_format
            average = sum / 6
            total += average
            first_last = first_sum + last_sum + 2
            result = first_last
            i = 1
            count = 0
            while result <= 36:
                result += i
                count += 1
            print(' '*count, end = '')
            print(f'|  {average:.2f} %')
            sum = 0
    print('-'*41)
    avg_total = total / matches
    print('Average', end = ' '*30)
    print(f'|  {avg_total:.2f} %')
