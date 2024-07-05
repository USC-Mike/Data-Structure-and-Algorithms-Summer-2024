cmake_minimum_required(VERSION 3.28)
project(Dictionary_Closed_Hashing C)

set(CMAKE_C_STANDARD 11)

add_executable(Dictionary_Closed_Hashing main.c
        Closed_Hash.h
        Closed_Hash.c)
