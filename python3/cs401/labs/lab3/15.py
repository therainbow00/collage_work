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
for l in range(len(products)):
    totals_product[products[l]['ProductId']] = 0

for i in range(len(Sales)):
    sale = Sales[i]

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
        for key, value in totals_product.items():
            if key == search:
                totals_product[key] += revenue
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
    print(f"The product that generated the least revenue over the entire year was {small_i}, and the amount was: ${small:,.2f}")
    #results(f'15. {small_i}, ${small:,.2f}')
