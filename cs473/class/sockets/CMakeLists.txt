cmake_minimum_required(VERSION 3.16)
project(sockets C)

set(CMAKE_C_STANDARD 11)



add_executable(unix-server unix-server.c)
add_executable(tcp-server tcp-server.c)
add_executable(tcp-connect tcp-connect.c)
add_executable(tcp-multi-connect tcp-poll.c dynamic-buffer.c dynamic-buffer.h)
