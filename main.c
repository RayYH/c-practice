#include "core/basic/data_types.h"
#include "core/basic/integers.h"
#include "core/misc/macros.h"

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
 */
int main() {
    custom_macro_usage();

    return 0;
}