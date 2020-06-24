#include "mathematical.h"

// links:
// https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
// https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/

struct container get_all_prime_factors(int n) {
    struct container c;
    int num = 1;
    int *ptr = (int *) malloc(num * sizeof(int));
    // the number of 2s that divide n
    while (n % 2 == 0) {
        n = n / 2;
        ptr = realloc(ptr, (num++) * sizeof(int));
        *(ptr + num - 2) = 2;
    }

    // n must be odd at this point.
    // So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        // While i divides n, save i and divide n
        while (n % i == 0) {
            ptr = realloc(ptr, (num++) * sizeof(int));
            *(ptr + num - 2) = i;
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2) {
        ptr = realloc(ptr, (num++) * sizeof(int));
        *(ptr + num - 2) = n;
    }

    c.elements = ptr;
    num--;
    c.count = num;

    return c;
}


/**
 * Conclusions:
 * gcd(a,b)=gcd(b,a)
 * gcd(-a,b)=gcd(a,b)
 * gcd(a,a)=|a|
 * gcd(a,0)=|a|
 * gcd(a,1)=1
 * gcd(a,b)=gcd(b, a mod b)
 * gcd(a,b)=gcd(b, a-b)
 */

int gcd_simple(int a, int b) {
    // everything divides 0
    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    if (a == b) {
        return a;
    }

    if (a > b) {
        return gcd_simple(a - b, b);
    } else {
        return gcd_simple(a, b - a);
    }
}