#!/usr/bin/env python3
import urllib.request
from utils import *


customers = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv")
products = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/products.csv")

Sales = []
for m in range(1, 13):
    Sales.append(read_csv(f"https://cs.indstate.edu/~lmay1/assets/sales-data/sales-{m:0>2}.csv"))

totals_product = {}
total_year = []
for i in range(len(Sales)):
    sale = Sales[i]
    for j in range(len(products)):
        totals_product[products[j]['ProductId']] = 0

    for line in sale:
        search = line['ProductId']
        product = [p for p in products if p['ProductId'] == search][0]
        profit = float(product['Price']) - float(product['Cost'])
        total_profit = profit * float(line['Quantity'])
        for l in range(len(product)):
            totals_product[search] += total_profit

    max = 0
    max_i = -1
    for key, value in totals_product.items():
        total = value
        if total > max:
            max = total
            max_i = key
    total_year.append(max_i)
    total_year.append(max)
small = total_year[1]
small_i = -1
for n in range(1, len(total_year), 2):
    total = total_year[n]
    if total < small:
        small = total
        small_i = total_year[n - 1]

if __name__ == "__main__":
    print(f"The product that was the least profitable over the entire year was {small_i}, and the amount was: ${small:,.2f}")
    results(f'17. {small_i}, ${small:,.2f}')
