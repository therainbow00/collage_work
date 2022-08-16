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
                totals_product[key] += total_profit

values_view = totals_product.values()
value_iterator = iter(values_view)
small = next(value_iterator)
small_i = -1
del totals_product['']
for key, value in totals_product.items():
    total = value
    if total < small:
        small = total
        small_i = key

if __name__ == "__main__":
    print(f"The product that was the least profitable over the entire year was {small_i}, and the amount was: ${small:,.2f}")
    results(f'17. {small_i}, ${small:,.2f}')
