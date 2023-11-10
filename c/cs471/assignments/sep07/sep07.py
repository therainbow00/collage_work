#!/usr/bin/env python3

NOBODY = -1
import sys

def main():
    max_size = int(sys.argv[1]) 
    min_size = int(sys.argv[2])
    
    print(f'the table: {max_size} {min_size}')
    
    pid = 0
    address = 0
    size = max_size

    found = False;
    print(f' | {address:06b}  {address}  | {size:06b}  {size}')
    
    s = input('enter a transaction: ')
    print(s)

    count = 0
    count1 = 0
    if s[0] == 'A':
        while found == False:
            if count > 0:
                s = input('enter a transaction: ')
            pid = int(s[2])
            if int(s[4:]) <= max_size and int(s[4:]) >= ((max_size / 2) + 1):
                if 9 > max_size > 0:
                    address = int(address + max_size)
                    print(f'  | {address:06b} {address} | {max_size:06b}  {max_size}')
                    address = int(address + max_size)
                    print(f'{pid} | {address:06b} {address} | {max_size:06b}  {max_size}')
                elif 99 > max_size > 10:
                    address = int(address + max_size)
                    print(f'  | {address:06b} {address} | {max_size:06b} {max_size}')
                    address = int(address + max_size)
                    print(f'{pid} | {address:06b} {address} | {max_size:06b} {max_size}')
                found = True
                count += 1
            else:
                if count1 > 0:
                    if 9 > max_size > 0:
                        print(f'  | {address:06b} {address} | {max_size:06b}  {max_size}')
                    elif 99 > max_size > 10:
                        print(f'  | {address:06b} {address} | {max_size:06b} {max_size}') 
                    address = int(address + max_size)
                max_size = int(max_size / 2)
                if count1 == 0:
                    if 9 >= max_size > 0:
                        print(f'  | {address:06b}  {address} | {max_size:06b}   {max_size}')
                    elif 99 >= max_size >= 10:
                        print(f'  | {address:06b}  {address} | {max_size:06b} {max_size}')        
                    address = int(address + max_size)
                count1 += 1

if __name__ == '__main__':
    main()
