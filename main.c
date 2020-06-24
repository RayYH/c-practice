#include "core/basic/data_types.h"
#include "core/basic/integers.h"
#include "core/misc/macros.h"
#include "core/basic/variables.h"

int global_int = 1;

void data_types_usage() {
    data_types();
    integer_promotions();
}

void integers() {
    two_s_complement();
}

/**
 * In C, if a function signature DOES NOT specify any argument, it means that the function can be called with any
 * number of parameters or without any parameters.
 *
 * How to compile:
 *
 * -Wall option enables all compiler’s warning messages. This option is recommended to generate better code.
 * $ gcc –Wall filename.c –o filename
 * $ ./filename
 *
 * 1. Pre-processing
 * 2. Compilation
 * 3. Assembly
 * 4. Linking
 *
 * show temp files
 * $ gcc –Wall –save-temps filename.c –o filename
 */
int main() {
    extern_keyword();

    return 0;
}