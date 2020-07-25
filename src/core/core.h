#ifndef C_PRACTICE_SRC_CORE_CORE_H_
#define C_PRACTICE_SRC_CORE_CORE_H_

/** the max value of generated random int number */
#define ELEM_MAX 100
/** the min value of generated random int number */
#define ELEM_MIN 1
/** horizontal line */
#define HL "____________________________________________________"
/** indicating start of a function */
#define START printf("\n");printf(__FUNCTION__);printf(":\n%s\n", HL);
/** just sending a new line to output */
#define END printf("\n");

#endif //C_PRACTICE_SRC_CORE_CORE_H_
