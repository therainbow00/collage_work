import sys
import struct
import shutil
import pwd


someimage = sys.argv[1]
sorce = sys.argv[2]
dest = sys.argv[3]

def readblock(n):
    with open(someimage, 'rb') as file:
        pos = file.seek(n)
        read = file.read(pos)
    return read

def main():
    with open(someimage, 'rb') as file:
        superblock = 1024

        descript_table = struct.unpack('<3I4H', readblock(superblock * 2)[:20])

        inode_table = struct.unpack('<2H5I2H18I', readblock(descript_table[2] * superblock + 256)[:100])
        root_block_size = inode_table[2]

        sorce_slash = 0
        sorce_index = 0


        dest_slash = 0
        dest_index = 0

        for i in range(len(dest)):
            if dest[i] == '/':
                dest_slash += 1
                dest_index += i
        
        direct = []
        if dest_slash > 1:

            count = 0
            start = 0
            scanned = 0
            check = False
            while len(dest):

                if len(direct) == 0:
                    for i in range(len(dest)):
                        if dest[i] == '/':
                            direct.append(dest[:i])
                            check = True
                            break
                        scanned += 1

                elif len(direct) >= 1:
                    check = False
                    start = scanned

                    i = 0
                    j = start
                    while i < len(dest):
                        if dest[scanned] == '/':
                            direct.append(dest[start:i + start])
                            count += 1
                            check = True
                            break
                        scanned += 1

                        i += 1
                        j += 1

                if check == True:
                    scanned += 1

                if len(direct) == dest_slash:
                    break

        elif dest_slash == 1:
            count = 0
            for i in range(len(dest)):
                if i == 0:
                    if dest[i] == '/':
                        direct.append('root')
                        break
                elif dest[i] == '/':
                    direct.append(dest[count:i - 1])
                    break


        root = inode_table[12] * superblock

        root_table = struct.unpack('<IH2B255c', readblock(root)[:263])

        new_pos = root
        next_record = root_table[1]
        if dest_slash == 1:

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

                            char = struct.unpack('<64c', readblock(54 * superblock)[:64])
                            string = ''.join(map(chr, read[:1339]))

                            with open(sorce, 'r') as s, open(dest, 'w+') as d:
                                d.write(string)

                            break

                    elif entry_file_type == 2:
                        name_length = root_table[4:entry_name_length + 4]
                        d = []
                        
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

                            entry_inode_table = struct.unpack('<2H5I2H18I', readblock(entry_inode * superblock)[:100])
                            entry_block = entry_inode_table[12]
                            inode_size = 256

                            entry_table = struct.unpack('<IH2B255c', readblock(entry_inode * superblock + inode_size * (entry_block - 1))[:263])
                            entry_size = entry_inode_table[2]
                            string = ''.join(map(chr, read[:entry_size]))

                            with open(sorce, 'r') as s, open(dest, 'w+') as d:
                                
                                d.write(string)

                            break
                else:
                    name = root_table[4]
                    name = ''.join(map(chr, name))

                    if entry_inode == 2:
                        root = inode_table[12] * superblock

                        root_table = struct.unpack('<IH2B255c', readblock(root)[:263])
                        print(root_table)
                        
                        root_inode = root_table[0] * superblock

                        root_table_inode = struct.unpack('<2H5I2H18I', readblock(root_inode)[:100])

                        
                        with open(sorce, 'r+b') as s:
                            shutil.copyfile(sorce, dest)
                    
                i += 1
        

if __name__ == '__main__':
    main()
