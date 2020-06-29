#include "assert_test.h"

// links:
// http://www.cplusplus.com/reference/cassert/

void assert_test() {
    int a = 10;
    int *b = NULL;
    int *c = NULL;
    b = &a;

    assert(b != NULL);
    assert(c == NULL);
}