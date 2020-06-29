#include "core/core.h"

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

void assert_tests() {
    assert_test();
}

void ctype_test() {
    isalnum_test();
    isalpha_test();
    isblank_test();
    iscntrl_test();
    isdigit_test();
    isgraph_test();
    islower_test();
    isprint_test();
    ispunct_test();
    isspace_test();
    isupper_test();
    isxdigit_test();
    all_characters();
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
int main(void) {
    printf("Run Assertions...\n");
    assert_test();
    ctype_test();

    printf("Done.\n");
    return 0;
}