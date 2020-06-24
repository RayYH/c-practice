#include "integers.h"

void two_s_complement() {
    int myInt;
    myInt = 0xFFFFFFE2;
    printf("%d\n", myInt);

    myInt = -30;
    printf("%X\n", myInt);
}

char *decimal_to_binary(int n) {
    int i;
    int size = sizeof(int) * 8;
    char *binaryPointer = malloc(sizeof(char) * size);
    for (i = 0; i < size; i++) {
        *(binaryPointer + i) = '0';
    }
    char *p = binaryPointer + size - 1;

    if (n == 0) {
        return binaryPointer;
    }

    bool minusZero = n < 0 ? true : false;

    n = abs(n);

    if (n >= pow(2, 63)) {
        exit(1);
    }


    int remainder;
    int quotient = n;
    while (quotient > 0) {
        remainder = quotient % 2;
        *(p--) = (remainder == 1) ? '1' : '0';
        quotient = quotient / 2;
    }

    if (minusZero) {
        *(binaryPointer) = '1';
    }

    return binaryPointer;
}