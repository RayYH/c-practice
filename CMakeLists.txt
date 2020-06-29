cmake_minimum_required(VERSION
        3.16)
project(c_practice
        C)

set(CMAKE_C_STANDARD
        11)

add_executable(
        c_practice
        main.c
        common.h
        # algorithms
        algorithms/sorting/bubble_sort.c
        algorithms/sorting/helper.c
        algorithms/sorting/helper.h
        algorithms/sorting/sorting.h
        algorithms/misc/mathematical.c
        algorithms/misc/mathematical.h
        # core
        core/basic/keywords.c
        core/basic/keywords.h
        core/basic/data_types.c
        core/basic/data_types.h
        core/basic/operators.h
        core/basic/operators.c
        core/basic/flow_control.h
        core/basic/flow_control.c
        core/basic/arrays.c
        core/basic/arrays.h
        core/basic/pointers.h
        core/basic/pointers.c
        core/basic/strings.c
        core/basic/strings.h
        core/basic/structs.h
        core/basic/structs.c
        core/basic/unions.c
        core/basic/unions.h
        core/basic/files.c
        core/basic/files.h
        core/basic/enums.c
        core/basic/enums.h
        core/basic/macros.c
        core/basic/macros.h
        core/basic/integers.h
        core/basic/integers.c
        core/basic/variables.h
        core/basic/variables.c
        core/basic/io.h
        core/basic/io.c
        core/std/assert_test.c
        core/std/assert_test.h
        core/std/ctype_test.c
        core/std/ctype_test.h
        ds/array.c
        ds/array.h
        ds/linked_list.c
        ds/linked_list.h
        core/std/limits_test.h
        core/std/limits_test.c
        core/std/std.h core/basic/basic.h core/core.h)

target_link_libraries(c_practice m)
