#include "assert_test.h"

// links:
// http://www.cplusplus.com/reference/cassert/

void print_number(int *myInt) {
    assert (myInt != NULL);
    printf("%d\n", *myInt);
}

void assert_test() {
    int a = 10;
    int *b = NULL;
    int *c = NULL;

    b = &a;

    print_number(b);
    print_number(c);
}