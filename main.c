#include "core/basic/data_types.h"
#include "core/basic/integers.h"
#include "core/basic/io.h"
#include "core/basic/variables.h"
#include "core/basic/enums.h"

int global_int;
// C allows a global variable to be declared again when first declaration doesn’t initialize the variable.
int global_int = 1;

void data_types_usage() {
    data_types();
    integer_promotions();
}

void integers() {
    two_s_complement();
}

void enum_usage() {
    enum_test();
    switch_enums();
}

void variable_usage() {
    const_keyword();
    static_keyword();
    void_keyword();
    extern_keyword();
    variables_assertion();
}

void io_usage() {
    //io_basic();
    //scanf_usage();
    //gets_usage();
    //puts_usage();
//    percent_n();
    //print_percent_char();
    //fflush_stdin();
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
    FILE *fp = fopen("test.txt", "r");

    if (fp == NULL) {
        /* Handle open error */
    }

    /* Do some processing with file*/

    if (fseek(fp, 0L, SEEK_SET) != 0) {
        /* Handle repositioning error */
    }

    /* Do some more precessing with file */

    return 0;
}