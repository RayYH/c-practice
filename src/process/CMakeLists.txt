cmake_minimum_required(VERSION 3.16)
project(c_practice_src_process C)
set(CMAKE_C_STANDARD 11)
set(exec_prefix "process_")

file(GLOB_RECURSE APP_SOURCES *.c)
include_directories(include include)

foreach (sourcefile ${APP_SOURCES})
    include_directories(include)
    get_filename_component(source_directory ${sourcefile} DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" source_directory
            ${sourcefile})
    string(REPLACE "/" "_" source_directory ${source_directory})
    string(REPLACE ".c" "" source_directory ${source_directory})
    set(exec_file "${exec_prefix}${source_directory}")
    message("Building exec: " ${exec_file})
    add_executable(${exec_file} ${sourcefile})
endforeach (sourcefile ${APP_SOURCES})
