#!/usr/bin/env python3
import urllib.request
from utils import *

products = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/products.csv")

Sales = []
for m in range(1, 13):
    Sales.append(read_csv(f"https://cs.indstate.edu/~lmay1/assets/sales-data/sales-{m:0>2}.csv"))

totals_product_month = {}

for j in range(len(products)):
    totals_product_month[products[j]['ProductId']] = 0

for i in range(len(Sales)):
    sale = Sales[i]
    for line in sale:
        search = line['ProductId']
        product = [p for p in products if p['ProductId'] == search][0]
        quantity = int(line['Quantity'])
        for key, value in totals_product_month.items():
            if key == search:
                totals_product_month[key] += quantity
values_view = totals_product_month.values()
value_iterator = iter(values_view)
small = next(value_iterator)
small_i = -1
del totals_product_month['']
for key, value in totals_product_month.items():
    total = value
    if total < small:
        small = total
        small_i = key

if __name__ == "__main__":
    print(f"The product that sold the worst in terms of quantity was {small_i}, and the number was: {small:,}")
    results(f'16. {small_i}, {small:,.2f}')
