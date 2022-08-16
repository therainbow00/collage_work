#!/usr/bin/env python3
from utils import *

customers = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv", ',', '\n')

first_names = []
for customer in customers:
    if customer['FirstName'] == '':
        first_names.append(customer['FirstName'])

if __name__ == "__main__":
    average = len(first_names) / len(customers) * 100
    print(f"percent of FirstName fields left blank: {average:.2f} %")
    results(f'01. {average:.2f} %')
