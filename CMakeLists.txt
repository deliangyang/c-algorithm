cmake_minimum_required(VERSION 3.13)
project(btree C)

set(CMAKE_C_STANDARD 99)

add_executable(btree main.c queue.c queue.h sort/insert_sort.c tree.c)