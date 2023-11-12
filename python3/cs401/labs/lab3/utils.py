#!/usr/bin/env python3
import urllib.request

def read_data(file_path):
    with urllib.request.urlopen(file_path) as req:
        data = req.read().decode("utf-8")
    return data

def read_file(path):
    with open(path) as req:
        data = req.read().strip().replace("\n\n", "\n")
    return data

def read_csv(file_path, field_sep = ",", record_sep = "\n"):
    data = read_data(file_path)
    line = data.split(record_sep)
    labels = line[0].split(field_sep)
    records = [ l.split(field_sep) for l in line[1:] ]

    list = []

    for record in records:
        di = {}
        for i in range(len(labels)):
            label = labels[i]
            if len(record) > i:
                val = record[i]
                di[label] = val
            else:
                di[label] = ""
        list.append(di)
    return list

def get_postal_dict():
    data = read_file("states.txt")
    li = data.split("\n")
    di = {}
    for i in range(0, len(li), 2):
        di[li[i + 1]] = li[i]
    di[''] = ''
    return di

def months(number):
    month = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
    for i in range(len(month)):
        if number == 0:
            return month[i]
        elif number == i:
            return month[i]
def results(answer):
    with open("results.txt", "a") as f:
        f.write(answer)
        f.write('\n')

if __name__ == "__main__":
    field_sep = ","
    record_sep = "\n"
    #read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv", field_sep, record_sep)
    #print(read_data("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv"))
    print(read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv", field_sep, record_sep))
