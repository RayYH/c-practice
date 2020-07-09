cmake_minimum_required(VERSION 3.16)
project(c_practice_src_apue C)
set(CMAKE_C_STANDARD 11)

include_directories(include include)
include_directories(lib lib)

file(GLOB LIB_SRC
        "lib/*.c"
        )

add_library(lib
        ${LIB_SRC}
        )

add_subdirectory(intro)