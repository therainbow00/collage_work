#!/usr/bin/env python3
import urllib.request
from utils import *

customers = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv", ',', '\n')
zip_codes = []
for customer in customers:
    if customer['Zip'] == '':
        zip_codes.append(customer['Zip'])


if __name__ == "__main__":
    average = len(zip_codes) / len(customers) * 100
    print(f"percent of Zip fields left blank: {average:.2f} %")
    results(f'03. {average:.2f} %')
