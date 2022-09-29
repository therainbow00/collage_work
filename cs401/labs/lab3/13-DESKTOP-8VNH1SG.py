#!/usr/bin/env python3
import urllib.request
from utils import *

products = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/products.csv")

Sales = []
for m in range(1, 13):
    Sales.append(read_csv(f"https://cs.indstate.edu/~lmay1/assets/sales-data/sales-{m:0>2}.csv"))

totals_product = {}
total_year = []
for j in range(len(products)):
    totals_product[products[j]['ProductId']] = 0
for i in range(len(Sales)):
    sale = Sales[i]
    for line in sale:
        search = line['ProductId']
        product = [p for p in products if p['ProductId'] == search][0]
        quantity = int(line['Quantity'])
        for key, value in totals_product.items():
            if key == search:
                totals_product[key] += quantity

max = 0
max_i = -1
for key, value in totals_product.items():
    total = value
    if total > max:
        max = total
        max_i = key

if __name__ == "__main__":
    print(f"The product that sold the best in terms of quantity was {max_i}, and the number was: {max:,}")
    #results(f'13. {max_i}, {max:,.2f}')
