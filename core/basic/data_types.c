#include "data_types.h"
#include <assert.h>

/**
 * Type     	            Size (bytes)        	        Format Specifier
 * int      	            at least 2, usually 4       	%d, %i
 * char     	            1       	                    %c
 * float        	        4       	                    %f
 * double       	        8       	                    %lf
 * short int        	    2 usually       	            %hd
 * unsigned int     	    at least 2, usually 4       	%u
 * long int     	        at least 4, usually 8       	%ld, %li
 * long long int            at least 8      	            %lld, %lli
 * unsigned long int        at least 4      	            %lu
 * unsigned long long int   at least 8      	            %llu
 * signed char      	    1       	                    %c
 * unsigned char        	1       	                    %c
 * long double      	    at least 10, usually 12 or 16   %Lf
 */

void data_types() {
    // define a constant - PI can't be modified
    const double PI = 3.14;
    // integer
    int age = 24;
    // char array - strings
    char name[] = "Ray";
    // char
    char grade = 'A';
    // float
    float gpa = 3.9f;
    // double
    double height = 174.80;
    printf("PI = %g\n", PI);
    printf("%s's age is %d\n", name, age);
    printf("%s's gpa is %f\n", name, gpa);
    printf("%s's height is %.1f\n", name, height);
    printf("%s's grade is %c\n", name, grade);

    // notice: sizeof is an operator
    printf("char: %lu\n", sizeof(char));
    printf("short int: %lu\n", sizeof(short int));
    printf("int: %lu\n", sizeof(int));
    printf("float: %lu\n", sizeof(float));
    printf("double: %lu\n", sizeof(double));
    printf("long int: %lu\n", sizeof(long int));
    printf("long long int: %lu\n", sizeof(long long int));
    printf("long double: %lu\n", sizeof(long double));

    // include stdbool.h we can use true and false
    printf("true: %d\n", true);
    printf("false: %d\n", false);
}

void data_types_overflow() {
    int maxInt = INT_MAX;
    int maxIntPlusOne = maxInt + 1;
    assert(maxIntPlusOne == INT_MIN);
    printf("int: %d + 1 = %d\n", maxInt, maxIntPlusOne);

    long maxLong = LONG_MAX;
    long maxLongPlusOne = maxLong + 1;
    printf("long: %ld + 1 = %ld\n", maxLong, maxLongPlusOne);
    assert(maxLongPlusOne == LONG_MIN);
}

void integer_promotions() {
    char a = 30, b = 40, c = 10;
    // a*b=1200 > 127
    char d = (a * b) / c;
    printf("%d\n", d); // still works

    char e = 0xfb;
    unsigned char f = 0xfb;

    // hex: 1111 1011
    // 2's complement of signed numbers: 10000101 = -5

    printf("%c: %d\n", e, e);
    printf("%c: %d\n", f, f);

    // when comparison operation is performed on e & f, they are first converted to int.
    assert(e != f);
}