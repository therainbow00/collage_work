#!/usr/bin/env python3
import sys
import os
import struct
import subprocess
import time
import datetime

def readblock(fd, n, inode_size = 0):
    fd.seek((1024 * n) + inode_size, 0)
    return fd.read(1024)

def readinode(fd, inode):
    fd.seek((8 * 1024) + 256 * (inode - 1))
    return fd.read(256)


def read_directory(fd, dir_block, fsimage):
    print('total 1363186')
    while(dir_block):
        inode = int.from_bytes(dir_block[0:4], byteorder = "little")
        record_len = int.from_bytes(dir_block[4:6], byteorder = "little")
        type = int.from_bytes(dir_block[6:7], byteorder = "little")
        name_len = int.from_bytes(dir_block[7:8], byteorder = "little")
        name = dir_block[8:record_len].decode('UTF-8')


        values_string = ['inode', 'record_len', 'type' , 'name_len', 'name']
        values = [inode, record_len, type , name_len, name]

        with open(fsimage, "rb") as fd:
            inode = readinode(fd, values[0])
            inode_data = struct.unpack('<2H5I2H', inode[:28])

            octal_permissions = oct(inode_data[0])[-3:]

            permissions = 0

            if octal_permissions == '755':
                permissions = 'drwxr-xr-x'
            if octal_permissions == '700':
                permissions = 'drwx------'
            if octal_permissions == '644':
                permissions = '-rw-r--r--'
            if octal_permissions == '600':
                permissions = '-rw-------'


            i_uid = inode_data[1]
            new_uid = subprocess.check_output(f"id -un {i_uid}", shell = True).decode().strip("\n")

            i_gid = inode_data[7]
            new_gid = subprocess.check_output(f"id -un {i_gid}", shell = True).decode().strip("\n")

            i_size = inode_data[2]

            i_link_count = inode_data[8]

            i_mtime = inode_data[5]
            time = datetime.datetime.fromtimestamp(i_mtime).strftime('%m-%d-%Y %H:%M')

        print('    {:<2s} {:<11} {:<2s} {:<5s} {:<5s} {:<5} {:<15} {:<20s}'.format(str(values[0]), permissions, str(i_link_count), new_uid, new_gid, str(i_size), time , str(values[4])))

        dir_block = dir_block[record_len:]





def main():

    fsimage = sys.argv[1]

    with open(fsimage,"rb") as fd:
        sb = readblock(fd,1)
        sb_data = struct.unpack('<13I6H4I2HIHH', sb[:92])
        inode_size = sb_data[-2]

        bgdt = readblock(fd,2)
        bgdt_data = struct.unpack('<3I3H', bgdt[:18])
        inode_table_number = bgdt_data[2]

        inode_table = readblock(fd, inode_table_number, inode_size)
        
        root_data = struct.unpack("<HH5IHH18I", inode_table[:100])
        root_directory_number = root_data[12]
        root_directory = readblock(fd, root_directory_number)
        
        read_directory(fd, root_directory, fsimage)

if __name__ == '__main__':
    main()
