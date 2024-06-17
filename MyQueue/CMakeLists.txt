cmake_minimum_required(VERSION 3.28)
project(MyQueue C)

set(CMAKE_C_STANDARD 11)

add_executable(MyQueue main.c
        QueueLinkedList.c
        QueueLinkedList.h)
