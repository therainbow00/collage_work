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
        
        inode_table_values = struct.unpack('<2H5I2H18I', read[:100])
        inode_table_mode_oct = oct(inode_table_values[0])
        inode_table_mode = inode_table_mode_oct[4:]
        if inode_table_mode_oct[2] == '4':

            root_block = inode_table_values[12]

            root = superblock * root_block
            bintree_inode = inode_table_number * superblock + inode_size * (12 - 1)
            bintree_contens = 54 * superblock
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
                            pos = file.seek(bintree_contens)

                            read = file.read(pos)

                            char = struct.unpack('<64c', read[:64])
                            string = ''.join(map(chr, read[:1339]))
                            print(string)
                            break

                    elif entry_file_type == 2:
                        name_length = root_table[4:entry_name_length + 4]
                        d = []
                        for l in range(len(name_length)):
                            name = ''.join(map(chr, name_length[l]))
                            d.append(name)

                        d.append('/')

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

if __name__ == '__main__':
    main()
