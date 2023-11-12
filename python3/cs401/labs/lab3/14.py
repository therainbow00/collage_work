#!/usr/bin/env python3
import urllib.request
from utils import *

customers = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv")
products = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/products.csv")

Sales = []
for m in range(1, 13):
    Sales.append(read_csv(f"https://cs.indstate.edu/~lmay1/assets/sales-data/sales-{m:0>2}.csv"))

totals_product = {}
for j in range(len(products)):
    totals_product[products[j]['ProductId']] = 0

for i in range(len(Sales)):
    sale = Sales[i]

    for line in sale:
        search = line['ProductId']
        product = [p for p in products if p['ProductId'] == search][0]
        profit = float(product['Price']) - float(product['Cost'])
        total_profit = profit * float(line['Quantity'])
        for key, value in totals_product.items():
            if key == search:
                totals_product[search] += total_profit

max = 0
max_i = -1
for key, value in totals_product.items():
    total = value
    if total > max:
        max = total
        max_i = key


if __name__ == "__main__":
    print(f"The product that was the most profitable over the entire year was {max_i}, and the amount was: ${max:,.2f}")
    results(f'14. {max_i}, ${max:,.2f}')
