#!/usr/bin/env python3
import urllib.request
from utils import *


customers = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv")
products = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/products.csv")
expenses = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/expenses.csv")

Sales = []
for m in range(1, 13):
    Sales.append(read_csv(f"https://cs.indstate.edu/~lmay1/assets/sales-data/sales-{m:0>2}.csv"))

gross_profit = 0
totals = [0] * 12
for i in range(len(Sales)):
    sale = Sales[i]
    for line in sale:
        search = line['ProductId']
        product = [p for p in products if p['ProductId'] == search][0]
        profit = float(product['Price']) - float(product['Cost'])
        gross_profit += profit * float(line['Quantity'])
    net_profit = gross_profit - float(expenses[i]['Expenses'])
    totals[i] = net_profit
    gross_profit = 0

small = totals[0]
small_i = -1
for i in range(len(totals)):

    total = totals[i]
    if total < small:
        small = total
        small_i = i

if __name__ == "__main__":
    print(f"The month that saw the smallest net profit was {months(small_i)}, and the value was: ${small:,.2f}")
    #results(f'11. {months(small_i)}, ${small:,.2f}')
