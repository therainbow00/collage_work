#!/usr/bin/env python3
import urllib.request
from utils import *

customers = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv", ',', '\n')
Switched = []
for customer in customers:
    if customer['State'].isdigit():
        Switched.append(customer['State'])


if __name__ == "__main__":
    average = len(Switched) / len(customers) * 100
    print(f"percent of Zip and State fields switched: {average:.2f} %")
    results(f'05. {average:.2f} %')
