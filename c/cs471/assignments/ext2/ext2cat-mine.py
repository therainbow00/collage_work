#!/usr/bin/env python3

import sys
import codecs
import struct
import binascii

arg1 = sys.argv[1]
arg2 = sys.argv[2]

def main():
    with open(arg1, 'rb') as file:
        superblock = 1024
        inode_size = 256
        block_decript_table = superblock * 2
        
        pos = file.seek(block_decript_table)
        read = file.read(pos)
        block_descript_values = struct.unpack('<3I4H', read[:20])
        
        inode_table_number = block_descript_values[2]
        inode_table = superblock * inode_table_number + inode_size
        #print(block_descript_values)
        pos = file.seek(inode_table)
        read = file.read(pos)
        
        slash = 0
        index = 0
        
        for i in range(len(arg2)):
            if arg2[i] == '/':
                slash += 1
                index += i
        #print('number of /:', dest_slash)
        #print('/ is at index:', dest_index)
        
        direct = []
        if slash > 1:
            #print('number of /:', dest_slash)
            count = 0
            start = 0
            scanned = 0
            check = False
            while len(arg2):
                #print('here')
                if len(direct) == 0:
                    for i in range(len(arg2)):
                        if dest[i] == '/':
                            direct.append(arg2[:i])
                            check = True
                            break
                        scanned += 1
                        #start += 1
                        #print('start:', start)
                    #print(direct)
                    #print(scanned)
                elif len(direct) >= 1:
                    check = False
                    start = scanned
                    #start += dest_slash - 2
                    #print('start:', start)
                    #print('scanned:', scanned)
                    i = 0
                    j = start
                    while i < len(arg2):
                        if arg2[scanned] == '/':
                            direct.append(arg2[start:i + start])
                            count += 1
                            check = True
                            break
                        scanned += 1
                        #start += 1
                        #start += 1
                        i += 1
                        j += 1
                        #print('i:', i)
                        #print('scanned:', scanned)
                if check == True:
                    scanned += 1
                #print(direct)
                if len(direct) == slash:
                    break

        elif slash == 1:
            count = 0
            for i in range(len(arg2)):
                if i == 0:
                    if arg2[i] == '/':
                        direct.append('root')
                        break
                elif arg2[i] == '/':
                    direct.append(arg2[count:i])
                    break
        #print(direct)
        #print(index)
        
        inode_table_values = struct.unpack('<2H5I2H18I', read[:100])
        #print(inode_table_values)
        inode_table_mode_oct = oct(inode_table_values[0])
        inode_table_mode = inode_table_mode_oct[4:]
        if inode_table_mode_oct[2] == '4':

            root_block = inode_table_values[12]

            root = superblock * root_block
            root_table_size = inode_table_values[2]
            
            pos = file.seek(root)

            read = file.read(pos)

            root_table = struct.unpack('<IH2B255c', read[:263])
            #print(root_table)
            next_record = root_table[1]

            end_root_table = root + superblock
            new_pos = root

            entry = 0
            i = 0
            tell = False
            if slash == 1:
                root = superblock * root_block
                
                while True:

                    if i > 0:
                        new_pos += next_record

                        pos = file.seek(new_pos)
                    else:

                        pos = file.seek(root)
                    read = file.read(pos)
                    root_table = struct.unpack('<IH2B255c', read[:263])
                    #print(root_table)
                    if next_record == root_table_size:
                        break

                    entry_inode = root_table[0]
                    next_record = root_table[1]
                    entry_name_length = root_table[2]
                    entry_file_type = root_table[3]
                    number = 3 + entry_name_length
                    is_file = False
                    for n in range(len(arg2)):
                        if arg2[n] == '.':
                            is_file = True
                            break
                        else:
                            is_file = False
                    if i > 0:
                        if entry_file_type == 1 and is_file == True:
                            name_length = root_table[4:entry_name_length + 4]
                            if entry_inode < 10:
                                #pass
                                print(f'inode:  {entry_inode}, next entry: {next_record}, name length: {entry_name_length}, file type: {entry_file_type}, name: ', end = '')
                            else:
                                #pass
                                print(f'inode: {entry_inode}, next entry: {next_record}, name length: {entry_name_length}, file type: {entry_file_type}, name: ', end = '')
                            
                            l = []
                            for j in range(len(name_length)):
                                name = ''.join(map(chr, name_length[j]))
                                l.append(name)
                                #print(name, end = '')
                            #l.append('/')
                            #print()
                            #d.append('/')
                            #print(d)
                            
                            #print(l)
                            new_index = index + 1
                            len_arg2 = arg2[new_index:]
                            
                            new_index = index + 1
                            #print(len(l))
                            #print(len(len_arg2))
                            if len(l) == len(len_arg2):
                                #print('here')
                                for k in range(len(l)):
                                    if l[k] == arg2[new_index]:
                                        #print(f'l[{k}]: {l[k]} = arg2[{new_index}]: {arg2[new_index]}')
                                        #print('checking if "tell" is true')
                                        tell = True
                                    else:
                                        tell = False
                                    new_index += 1
                            if tell == True:

                                pos = file.seek(inode_table_number * superblock + inode_size * (entry_inode - 1))

                                read = file.read(pos)

                                entry_inode_table = struct.unpack('<2H5I2H18I', read[:100])
                                entry_block = entry_inode_table[12]
                                #print(entry_inode_table)
                                #bintree_inode = inode_table_number * superblock + inode_size * (12 - 1)
                                entry_size = entry_inode_table[2]
                                entry_contens = entry_inode_table[12] * superblock
                                pos = file.seek(entry_contens)

                                read = file.read(pos)

                                char = struct.unpack('<64c', read[:64])
                                #print(char)
                                print(''.join(map(chr, read[:entry_size])))
                                break

                        elif entry_file_type == 2:
                            name_length = root_table[4:entry_name_length + 4]
                            if entry_inode < 10:
                                #pass
                                print(f'inode:  {entry_inode}, next entry: {next_record}, name length: {entry_name_length}, file type: {entry_file_type}, name: ', end = '')
                            else:
                                #pass
                                print(f'inode: {entry_inode}, next entry: {next_record}, name length: {entry_name_length}, file type: {entry_file_type}, name: ', end = '')

                            d = []
                            for l in range(len(name_length)):
                                name = ''.join(map(chr, name_length[l]))
                                d.append(name)
                                #print(name, end = '')
                            #print('/')

                            #d.append('/')

                            for m in range(len(d)):
                                if d[m] == arg2[m]:
                                    tell = True

                                else:
                                    tell = False

                                    break

                            if tell == True:
                                pos = file.seek(entry_inode * superblock)

                                read = file.read(pos)

                                entry_inode_table = struct.unpack('<2H5I2H18I', read[:100])
                                entry_block = entry_inode_table[12]
                                pos = file.seek(entry_inode * superblock + inode_size * (entry_block - 1))
                                read = file.read(pos)
                                entry_table = struct.unpack('<IH2B255c', read[:263])
                                entry_size = entry_inode_table[2]
                                print(''.join(map(chr, read[:entry_size])))
                                break
                    else:
                        if entry_file_type == 1 and is_file == True:
                            name_length = root_table[4:entry_name_length + 4]
                            l = []
                            for j in range(len(name_length)):
                                name = ''.join(map(chr, name_length[j]))
                                l.append(name)
                            #print(l)
                            for k in range(len(l)):
                                
                                if l[k] == arg2[k]:
                                    tell = True
                                else:
                                    tell = False
                            if tell == True:
                                pos = file.seek(inode_table_number * superblock + inode_size * (entry_inode - 1))

                                read = file.read(pos)

                                entry_inode_table = struct.unpack('<2H5I2H18I', read[:100])
                                entry_block = entry_inode_table[12]
                                #print(entry_inode_table)
                                #bintree_inode = inode_table_number * superblock + inode_size * (12 - 1)
                                entry_contens = entry_inode_table[12] * superblock
                                pos = file.seek(entry_contens)

                                read = file.read(pos)

                                char = struct.unpack('<64c', read[:64])
                                string = ''.join(map(chr, read[:1339]))
                                #print(string)
                                break

                        elif entry_file_type == 2:
                            name_length = root_table[4:entry_name_length + 4]
                            if entry_inode < 10:
                                #pass
                                print(f'inode:  {entry_inode}, next entry: {next_record}, name length: {entry_name_length}, file type: {entry_file_type}, name: ', end = '')
                            else:
                                #pass
                                print(f'inode: {entry_inode}, next entry: {next_record}, name length: {entry_name_length}, file type: {entry_file_type}, name: ', end = '')
                            
                            d = []
                            for l in range(len(name_length)):
                                name = ''.join(map(chr, name_length[l]))
                                d.append(name)
                                #print(name, end = '')
                                #print('/')
                            #d.append('/')

                            for m in range(len(d)):
                                if d[m] == arg2[m]:
                                    tell = True

                                else:
                                    tell = False

                                    break

                            if tell == True:
                                pos = file.seek(entry_inode * superblock)

                                read = file.read(pos)

                                entry_inode_table = struct.unpack('<2H5I2H18I', read[:100])
                                entry_block = entry_inode_table[12]
                                pos = file.seek(entry_inode * superblock + inode_size * (entry_block - 1))
                                read = file.read(pos)
                                entry_table = struct.unpack('<IH2B255c', read[:263])
                                entry_size = entry_inode_table[2]
                                print(''.join(map(chr, read[:entry_size])))
                                break
                    i += 1
            elif slash > 1:
                #print('here')
                i = 0
                tell = False
                index = 0
                while True:
    
                    if i > 0:
                        new_pos += next_record
    
                        pos = file.seek(new_pos)
                    else:
    
                        pos = file.seek(root)
                    read = file.read(pos)
                    root_table = struct.unpack('<IH2B255c', read[:263])
                    if next_record == root_block_size:
                        break
                    #print(root_table)
                    entry_inode = root_table[0]
                    next_record = root_table[1]
                    entry_name_length = root_table[2]
                    entry_file_type = root_table[3]
                    number = 3 + entry_name_length
                    is_file = False
                    
                    for n in range(len(sorce)):
                        if sorce[n] == '.':
                            is_file = True
                            break
                        else:
                            is_file = False
                    
                    name_length = root_table[4:entry_name_length + 4]
                    if i > 0:
                        if entry_file_type == 1 and is_file == True:
                            name_length = root_table[4:entry_name_length + 4]
                            l = []
                            if entry_inode < 10:
                                #pass
                                print(f'inode:  {entry_inode}, next entry: {next_record}, name length: {entry_name_length}, file type: {entry_file_type}, name: ', end = '')
                            else:
                                #pass
                                print(f'inode: {entry_inode}, next entry: {next_record}, name length: {entry_name_length}, file type: {entry_file_type}, name: ', end = '')
                            
                            for j in range(len(name_length)):
                                name = ''.join(map(chr, name_length[j]))
                                #print(name, end = '')
                                l.append(name)
                            #print()
                            #print(l)
    
                            start = dest_index + 1
                            v = 0
                            #print(sorce[start:])
                            #print(l)
                            if len(dest[start:]) == len(l):
                                for k in range(start, len(dest), 1):
                                    if l[v] == dest[k]:
                                        #print(l[v], end = '')
                                        tell = True
                                    else:
                                        tell = False
                                    v += 1
                                if tell == True: 
                                    #print()
                                    pass
    
    
    
                            if tell == True:
                                #print('here')
                                
                                        
                                pos = file.seek(54 * superblock)
    
                                read = file.read(pos)
    
                                char = struct.unpack('<64c', read[:64])
                                string = ''.join(map(chr, read[:1339]))
                                #print(string)
                                with open(sorce, 'r') as s, open(dest, 'w+') as d:
                                    if s == None:
                                        pass
                                        #print('file faild to open')
                                    else:
                                        pass
                                        #print('file opened')
                                        if d == None:
                                            pass
                                            #print('file faild to write into')
                                        else:
                                            d.write(string)
                                            #print('success')
                                break
    
                        elif entry_file_type == 2:
                            name_length = root_table[4:entry_name_length + 4]
                            d = []
                            if entry_inode < 10:
                                #pass
                                print(f'inode:  {entry_inode}, next entry: {next_record}, name length: {entry_name_length}, file type: {entry_file_type}, name: ', end = '')
                            else:
                                #pass
                                print(f'inode: {entry_inode}, next entry: {next_record}, name length: {entry_name_length}, file type: {entry_file_type}, name: ', end = '')
                            
                            for l in range(len(name_length)):
                                name = ''.join(map(chr, name_length[l]))
                                d.append(name)
                                #print(name, end = '')
                            #print('/')
                            d.append('/')
                            #d.append('/')
                            #print(d)
                            
                            for m in range(len(d) - 1):
                                if d[m] == direct[index][m]:
                                    tell = True
                                    #print(f'{d[m]} == {direct[index][m]}')
                                    #print(f'{d[m]} is in {direct[index]}')
                                else:
                                    tell = False
    
                                    break
                            
                            if tell == True:
                                #print(f'looking at "{direct[index]}"')
                                pos = file.seek(entry_inode * superblock)
    
                                read = file.read(pos)
    
                                entry_inode_table = struct.unpack('<2H5I2H18I', read[:100])
                                entry_block = entry_inode_table[12]
                                inode_size = 256
                                pos = file.seek(entry_inode * superblock + inode_size * (entry_block - 1))
                                read = file.read(pos)
                                entry_table = struct.unpack('<IH2B255c', read[:263])
                                entry_size = entry_inode_table[2]
                                string = ''.join(map(chr, read[:entry_size]))
                                #print(string)
                                with open(sorce, 'r') as s, open(dest, 'w+') as d:
                                    if s == None:
                                        pass
                                        #print('file faild to open')
                                    else:
                                        pass 
                                        #print('file opened')
                                        if d == None:
                                            pass
                                            #print('file faild to write into')
                                        else:
                                            d.write(string)
                                            #print('success')
                                break
                    else:
                        name = root_table[4]
                        name = ''.join(map(chr, name))
                        #print(f'inode:  {entry_inode}, next entry:  {next_record}, name length:  {entry_name_length}, file type: {entry_file_type}, name: {name}/')
                        
                        root_inode = file.seek(12 * superblock)
    
                        read = file.read(root_inode)
    
                        entry_inode_table = struct.unpack('<2H5I2H18I', read[:100])
                        #print(entry_inode_table)
                        #print(pwd.getpwuid(entry_inode_table[1]))
                        
                        with open(sorce, 'r') as s:
                            if s == None:
                                pass
                                #print('file faild to open')
                            else: 
                                #print('file opened')
                                shutil.copyfile(sorce, dest)
                                #print('success')
                        #print(name)
                        
                    i += 1
            
if __name__ == '__main__':
    main()
