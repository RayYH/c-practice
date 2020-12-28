cmake_minimum_required(VERSION 3.16)
project(c_practice_src_apue_intro C)
set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(lib)
link_libraries(dsa_lib)

add_executable(btree btree.c)
