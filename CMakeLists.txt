cmake_minimum_required(VERSION 3.16)
project(c_practice C)

set(CMAKE_C_STANDARD 11)

add_executable(c_practice main.c algorithms/sorting/bubble_sort.c algorithms/sorting/helper.c algorithms/sorting/helper.h algorithms/sorting/sorting.h core/intro/keywords.c core/intro/keywords.h common.h core/intro/data_types.c core/intro/data_types.h core/intro/operators.h core/intro/operators.c)