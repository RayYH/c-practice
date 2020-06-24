#ifndef C_PRACTICE_MATHEMATICAL_H
#define C_PRACTICE_MATHEMATICAL_H

#include "../../common.h"

struct container {
    // whole elements
    int *elements;
    int count;
};

int gcd_simple(int a, int b);

struct container get_all_prime_factors(int n);

int gcd(int a, int b);

#endif //C_PRACTICE_MATHEMATICAL_H
