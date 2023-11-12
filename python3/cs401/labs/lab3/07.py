#!/usr/bin/env python3
import urllib.request
from utils import *


customers = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv")
products = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/products.csv")

Sales = []
for m in range(1, 13):
    Sales.append(read_csv(f"https://cs.indstate.edu/~lmay1/assets/sales-data/sales-{m:0>2}.csv"))

count = 0
totals = [0] * 12
for i in range(len(Sales)):
    sale = Sales[i]

    for line in sale:
        search = line['ProductId']
        product = [p for p in products if p['ProductId'] == search][0]
        profit = float(product['Price']) - float(product['Cost'])
        total_profit = profit * float(line['Quantity'])

        totals[i] += total_profit
max = 0
max_i = -1
for i in range(len(totals)):
    total = totals[i]
    if total > max:
         max = total
         max_i = i

if __name__ == "__main__":
    print(f"The month that saw the largest gross profit was {months(max_i)}, and the value was: ${max:,.2f}")
    results(f'07. {months(max_i)}, ${max:,.2f}')
