cmake_minimum_required(VERSION 3.16)
project(c_practice_src C)
set(CMAKE_C_STANDARD 11)

# Core syntax of C
add_subdirectory(core)
# std libs of C
add_subdirectory(std)
# Data Structure and Algorithms
add_subdirectory(dsa)
# IPC
add_subdirectory(ipc)
# Miscellaneous
add_subdirectory(misc)
# Advanced Programming in the UNIX Environment
add_subdirectory(apue)
