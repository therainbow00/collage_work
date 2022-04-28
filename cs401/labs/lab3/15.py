#!/usr/bin/env python3
import urllib.request
from utils import *


state_conversion = get_postal_dict()
customers = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/customers.csv")
products = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/products.csv")

sales_tax = read_csv("https://cs.indstate.edu/~lmay1/assets/sales-data/tax.csv")
sales_tax.append({
    'State': '',
    'Rate': '0%',
    'Rank': 'N/A',
})

for c in customers:
    if c['State'].isdigit():
        c['State'], c['Zip'] = c['Zip'], c['State']

Sales = []
for m in range(1, 13):
    Sales.append(read_csv(f"https://cs.indstate.edu/~lmay1/assets/sales-data/sales-{m:0>2}.csv"))


totals_product = {}
total_year = []
same = False
for i in range(len(Sales)):
    sale = Sales[i]
    for l in range(len(products)):
        totals_product[products[l]['ProductId']] = 0

    for line in sale:
        search = line['ProductId']
        product = [p for p in products if p['ProductId'] == search][0]
        revenue = float(line['Quantity']) * float(product['Price'])
        custId = line['CustomerId']
        customer = [c for c in customers if c['CustomerId'] == custId][0]
        long_state = state_conversion[customer['State']]
        tax = [t for t in sales_tax if t['State'] == long_state][0]
        if tax['Rate'] == '' and tax['State'] == '' and tax['Rank'] == '':
            tax['Rate'] = 0
            tax['Rank'] = 0
            tax['State'] = ''
            f_tax = float(tax['Rate'])
            tax_rate = f_tax / 100

        elif tax['Rate'] == 0:
            tax['Rate'] = 0
            f_tax = float(tax['Rate'])
            tax_rate = f_tax / 100

        else:
            s_tax = tax['Rate']
            f_tax = s_tax[:-1]
            tax_rate = float(f_tax) / 100
        revenue *= 1 + tax_rate
        for l in range(len(product)):
            totals_product[search] += revenue


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
    print(f"The product that generated the least revenue over the entire year was {small_i}, and the amount was: ${small:,.2f}")
    results(f'15. {small_i}, ${small:,.2f}')
