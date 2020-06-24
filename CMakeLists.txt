cmake_minimum_required(VERSION 3.16)
project(c_practice C)

set(CMAKE_C_STANDARD 11)

add_executable(
        c_practice main.c algorithms/sorting/bubble_sort.c algorithms/sorting/helper.c algorithms/sorting/helper.h algorithms/sorting/sorting.h core/basic/keywords.c core/basic/keywords.h common.h core/basic/data_types.c core/basic/data_types.h core/basic/operators.h core/basic/operators.c core/basic/flow_control.h core/basic/flow_control.c core/basic/arrays.c core/basic/arrays.h core/basic/pointers.h core/basic/pointers.c core/basic/strings.c core/basic/strings.h core/basic/structs.h core/basic/structs.c core/basic/unions.c core/basic/unions.h core/basic/files.c core/basic/files.h core/misc/enums.c core/misc/enums.h core/misc/macros.c core/misc/macros.h core/std/assert_test.c core/std/assert_test.h core/std/ctype_test.c core/std/ctype_test.h ds/array.c ds/array.h algorithms/misc/mathematical.c algorithms/misc/mathematical.h ds/linked_list.c ds/linked_list.h core/basic/integers.h core/basic/integers.c core/std/limits_test.h core/std/limits_test.c core/basic/variables.h core/basic/variables.c)