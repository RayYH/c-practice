cmake_minimum_required(VERSION 3.16)
project(c_practice C)

set(CMAKE_C_STANDARD 11)

add_executable(c_practice main.c algorithms/sorting/bubble_sort.c algorithms/sorting/helper.c algorithms/sorting/helper.h algorithms/sorting/sorting.h core/basic/keywords.c core/basic/keywords.h common.h core/basic/data_types.c core/basic/data_types.h core/basic/operators.h core/basic/operators.c core/basic/flow_control.h core/basic/flow_control.c core/basic/arrays.c core/basic/arrays.h)