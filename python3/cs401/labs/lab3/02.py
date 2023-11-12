#!/usr/bin/env python3
import urllib.request
from utils import *

customers = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv", ',', '\n')
last_names = []
for customer in customers:
    if customer['LastName'] == '':
        last_names.append(customer['LastName'])


if __name__ == "__main__":
    average = len(last_names) / len(customers) * 100
    print(f"percent of LastName fields left blank: {average:.2f} %")
    results(f'02. {average:.2f} %')
