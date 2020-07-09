cmake_minimum_required(VERSION 3.16)
project(c_practice_src_apue_intro C)
set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(lib)
link_libraries(lib)

add_executable(custom_ls
        custom_ls.c
        )