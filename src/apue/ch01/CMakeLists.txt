cmake_minimum_required(VERSION 3.16)
project(c_practice_src_apue_intro C)
set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(lib)
link_libraries(lib)

# Add executables
add_executable(custom_ls custom_ls.c)
add_executable(custom_cat custom_cat.c)
add_executable(custom_copy custom_copy.c)
add_executable(display_pid display_pid.c)
add_executable(shell1 shell1.c)
add_executable(shell2 shell2.c)
