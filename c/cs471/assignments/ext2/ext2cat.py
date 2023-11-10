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

        pos = file.seek(inode_table)
        read = file.read(pos)
        print(struct.unpack('<2H5I2H18I', read[:100]))
        
        slash = 0
        index = 0
        
        for i in range(len(arg2)):
            if arg2[i] == '/':
                slash += 1
                index += i
        
        direct = []
        if slash > 1:

            count = 0
            start = 0
            scanned = 0
            check = False
            while len(arg2):

                if len(direct) == 0:
                    for i in range(len(arg2)):
                        if dest[i] == '/':
                            direct.append(arg2[:i])
                            check = True
                            break
                        scanned += 1

                elif len(direct) >= 1:
                    check = False
                    start = scanned

                    i = 0
                    j = start
                    while i < len(arg2):
                        if arg2[scanned] == '/':
                            direct.append(arg2[start:i + start])
                            count += 1
                            check = True
                            break
                        scanned += 1

                        i += 1
                        j += 1

                if check == True:
                    scanned += 1

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
        
        inode_table_values = struct.unpack('<2H5I2H18I', read[:100])

        inode_table_mode_oct = oct(inode_table_values[0])
        inode_table_mode = inode_table_mode_oct[4:]
        if inode_table_mode_oct[2] == '4':

            root_block = inode_table_values[12]

            root = superblock * root_block
            root_table_size = inode_table_values[2]
            
            pos = file.seek(root)

            read = file.read(pos)

            root_table = struct.unpack('<IH2B255c', read[:263])

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
                                pass

                            else:
                                pass
                            
                            l = []
                            for j in range(len(name_length)):
                                name = ''.join(map(chr, name_length[j]))
                                l.append(name)

                            new_index = index + 1
                            len_arg2 = arg2[new_index:]
                            
                            new_index = index + 1

                            if len(l) == len(len_arg2):

                                for k in range(len(l)):
                                    if l[k] == arg2[new_index]:

                                        tell = True
                                    else:
                                        tell = False
                                    new_index += 1
                            if tell == True:

                                pos = file.seek(inode_table_number * superblock + inode_size * (entry_inode - 1))

                                read = file.read(pos)

                                entry_inode_table = struct.unpack('<2H5I2H18I', read[:100])
                                entry_block = entry_inode_table[12]

                                entry_size = entry_inode_table[2]
                                entry_contens = entry_inode_table[12] * superblock
                                pos = file.seek(entry_contens)

                                read = file.read(pos)

                                char = struct.unpack('<64c', read[:64])

                                print(''.join(map(chr, read[:entry_size])))
                                break

                        elif entry_file_type == 2:
                            name_length = root_table[4:entry_name_length + 4]
                            if entry_inode < 10:
                                pass

                            else:
                                pass

                            d = []
                            for l in range(len(name_length)):
                                name = ''.join(map(chr, name_length[l]))
                                d.append(name)

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

                                entry_contens = entry_inode_table[12] * superblock
                                pos = file.seek(entry_contens)

                                read = file.read(pos)

                                char = struct.unpack('<64c', read[:64])
                                string = ''.join(map(chr, read[:1339]))

                                break

                        elif entry_file_type == 2:
                            name_length = root_table[4:entry_name_length + 4]
                            if entry_inode < 10:
                                pass

                            else:
                                pass
                            
                            d = []
                            for l in range(len(name_length)):
                                name = ''.join(map(chr, name_length[l]))
                                d.append(name)

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
                                pass

                            else:
                                pass

                            
                            for j in range(len(name_length)):
                                name = ''.join(map(chr, name_length[j]))

                                l.append(name)


                            start = dest_index + 1
                            v = 0

                            if len(dest[start:]) == len(l):
                                for k in range(start, len(dest), 1):
                                    if l[v] == dest[k]:

                                        tell = True
                                    else:
                                        tell = False
                                    v += 1
                                if tell == True: 

                                    pass
    
    
                            if tell == True:

                                pos = file.seek(54 * superblock)

                                read = file.read(pos)

                                char = struct.unpack('<64c', read[:64])
                                pos = file.seek(entry_inode * superblock + inode_size * (entry_block - 1))
                                read = file.read(pos)
                                entry_table = struct.unpack('<IH2B255c', read[:263])
                                entry_size = entry_inode_table[2]
                                #print(''.join(map(chr, read[:entry_size])))

    
                        elif entry_file_type == 2:
                            name_length = root_table[4:entry_name_length + 4]
                            d = []
                            if entry_inode < 10:
                                pass

                            else:
                                pass

                            
                            for l in range(len(name_length)):
                                name = ''.join(map(chr, name_length[l]))
                                d.append(name)

                            d.append('/')

                            
                            for m in range(len(d) - 1):
                                if d[m] == direct[index][m]:
                                    tell = True

                                else:
                                    tell = False
    
                                    break
                            
                            if tell == True:

                                pos = file.seek(entry_inode * superblock)
    
                                read = file.read(pos)
    
                                entry_inode_table = struct.unpack('<2H5I2H18I', read[:100])
                                entry_block = entry_inode_table[12]
                                inode_size = 256
                                pos = file.seek(entry_inode * superblock + inode_size * (entry_block - 1))
                                read = file.read(pos)
                                entry_table = struct.unpack('<IH2B255c', read[:263])
                                entry_size = entry_inode_table[2]
                                #print(''.join(map(chr, read[:entry_size])))
                                
                    else:
                        name = root_table[4]
                        name = ''.join(map(chr, name))
                        
                        root_inode = file.seek(12 * superblock)

                        read = file.read(root_inode)

                        entry_inode_table = struct.unpack('<2H5I2H18I', read[:100])

                        
                    i += 1
            
if __name__ == '__main__':
    main()
