cmake_minimum_required(VERSION 3.16)
project(c_practice C)

set(CMAKE_C_STANDARD 11)

add_executable(c_practice main.c algorithms/sorting/bubble_sort.c algorithms/sorting/helper.c algorithms/sorting/helper.h algorithms/sorting/sorting.h)