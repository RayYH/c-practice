cmake_minimum_required(VERSION 3.16)
project(c_practice_src_dsa_leetcode C)
set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(lib)
link_libraries(lib)

add_executable(p0001 p0001.c)
