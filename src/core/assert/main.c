#include "assert.h"
#include "stdio.h"

int main(void) {
    int a = 10;
    int *b = NULL;
    int *c = NULL;
    b = &a;

    assert(b != NULL);
    assert(c == NULL);

    return 0;
}