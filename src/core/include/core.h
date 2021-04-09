#ifndef C_PRACTICE_SRC_CORE_INCLUDE_CORE_H_
#define C_PRACTICE_SRC_CORE_INCLUDE_CORE_H_

/** some std headers */
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "assert.h"
#include "ctype.h"
#include "string.h"
#include "stdbool.h"
#include "float.h"
#include "limits.h"
#include "stdarg.h"
/** a global variable */
int global_int = 1;
/** the max value of generated random int number */
#define ELEM_MAX 100
/** the min value of generated random int number */
#define ELEM_MIN 1
/** horizontal line */
#define HL "____________________________________________________"
/** indicating start of a function */
#define START printf("\n");printf(__FUNCTION__);printf(":\n%s\n", HL);
/** just output a linefeed when function ends */
#define END printf("\n");

#endif //C_PRACTICE_SRC_CORE_INCLUDE_CORE_H_
