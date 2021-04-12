cmake_minimum_required(VERSION 3.16)
project(c_practice_src C)
set(CMAKE_C_STANDARD 11)

# Core syntax of C
add_subdirectory(core)
# Algorithms
add_subdirectory(algorithms)
# std libs of C
add_subdirectory(std)
# Data Structure and Algorithms
add_subdirectory(dsa)
# Process management
add_subdirectory(process)
# IPC
add_subdirectory(ipc)
# Miscellaneous
add_subdirectory(misc)
# Advanced Programming in the UNIX Environment
add_subdirectory(apue)
# Online judge
add_subdirectory(oj)
