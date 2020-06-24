#ifndef C_PRACTICE_MACROS_H
#define C_PRACTICE_MACROS_H

#include "../../common.h"
// After the pre-processing of a C program, a .i file is generated which is passed to the compiler for compilation.

// In C, for macros with arguments, there can’t be any space between macro name and open parenthesis.
#define MACRO_INTEGER_MAX 100
#define INCREMENT(x) ++x
#define MULTIPLY(x, y) x*y
#define MULTIPLY2(a, b) ((a)*(b))
#define MERGE(a, b) a##b
#define GET(a) #a
#define SQUARE(x) x*x
#define PRINT(i, limit) while (i < limit) \
{ \
    printf("Hello World!\n"); \
    i++; \
}
// if a macro is not defined, the pre-processor assigns 0 to it by default.
#if X == 0
#define Y 5
#endif

// - was regarded as unary operator here !!!!
#define A -B
#define B -C
#define C 5

#define D -E // - -1*2+3 = 5 here, -- is equivalent to - -
#define E -F // - 1*2+3 = 1,
#define F MULTIPLY(1, 2)+3 // 1*2+3 = 5
#define G - -E

void std_macro_usage();

void custom_macro_usage();

#endif //C_PRACTICE_MACROS_H
