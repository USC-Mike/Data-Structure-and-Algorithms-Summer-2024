cmake_minimum_required(VERSION 3.28)
project(First_Come_First_Serve C)

set(CMAKE_C_STANDARD 11)

add_executable(First_Come_First_Serve main.c
        FCFS_Process.h
        FCFS_Process.c)
