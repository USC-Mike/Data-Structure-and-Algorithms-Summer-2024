cmake_minimum_required(VERSION 3.28)
project(MyStack C)

set(CMAKE_C_STANDARD 11)

add_executable(MyStack main.c
        StackArray.c
        StackArray.h
        StackLinkedList.c
        StackLinkedList.h)
