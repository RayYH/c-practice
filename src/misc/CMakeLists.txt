cmake_minimum_required(VERSION 3.16)
project(c_practice_src_core C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS -pthread)

file(GLOB_RECURSE APP_SOURCES *.c)
include_directories(include include)

foreach (sourcefile ${APP_SOURCES})
    include_directories(include)
    get_filename_component(source_directory ${sourcefile} DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" source_directory
            ${sourcefile})
    string(REPLACE "/" "_" source_directory ${source_directory})
    string(REPLACE ".c" "" source_directory ${source_directory})
    message("Building exec: " ${source_directory})
    add_executable(${source_directory} ${sourcefile})
endforeach (sourcefile ${APP_SOURCES})
