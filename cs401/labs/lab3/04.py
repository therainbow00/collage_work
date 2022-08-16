#!/usr/bin/env python3
import urllib.request
from utils import *

customers = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv", ',', '\n')
States = []
for customer in customers:
    if customer['State'] == '':
        States.append(customer['State'])


if __name__ == "__main__":
    average = len(States) / len(customers) * 100
    print(f"percent of State fields left blank: {average:.2f} %")
    results(f'04. {average:.2f} %')
