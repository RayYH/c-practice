cmake_minimum_required(VERSION 3.16)
project(c_practice_src_dsa C)
set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(lib)
link_libraries(lib)


file(GLOB LIB_SRC
        "lib/*.c"
        )

add_library(dsa_lib
        ${LIB_SRC}
        )

add_subdirectory(sorting)
add_subdirectory(leetcode)
add_subdirectory(list)
