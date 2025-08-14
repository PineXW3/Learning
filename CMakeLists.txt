cmake_minimum_required(VERSION 3.31)
project(Hashtable C)

set(CMAKE_C_STANDARD 23)

add_executable(Hashtable main.c
        linked_list.h
        linked_list.c
        hashtable.c
        hashtable.h)
