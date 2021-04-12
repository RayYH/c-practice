#ifndef C_PRACTICE_SRC_CORE_INCLUDE_CORE_H_
#define C_PRACTICE_SRC_CORE_INCLUDE_CORE_H_

/** std headers */
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
/** horizontal line */
#define HL "____________________________________________________"
/** indicating start of a function */
#define START printf("\n");printf(__FUNCTION__);printf(":\n%s\n", HL);
/** just output a linefeed when function ends */
#define END printf("\n");

#endif //C_PRACTICE_SRC_CORE_INCLUDE_CORE_H_
