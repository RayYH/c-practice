#include "variables.h"

void display_variables() {

}

// the extern keyword extends the visibility of the C variables and C functions.
// Since functions are visible throughout the program by default, the use of extern is not needed in function
// declarations or definitions. Its use is implicit.
// When extern is used with a variable, it’s only declared, not defined.
void extern_keyword() {
    // see main.c file
    extern int global_int;
    assert(global_int == 1);
    global_int = 10;
    assert(global_int == 10);
}

void static_keyword() {

}