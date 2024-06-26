cmake_minimum_required(VERSION 3.28)
project(Dictionary_Open_Hashing C)

set(CMAKE_C_STANDARD 11)

add_executable(Dictionary_Open_Hashing main.c
        Open_Hash.h
        Open_Hash.c)
