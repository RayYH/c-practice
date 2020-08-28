/**
 *******************************************************************************
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
 *******************************************************************************
 */

#include "stdio.h"
#include "limits.h"
#include "assert.h"
#include "stdbool.h"
#include "core.h"

/**
 * Common data types usage.
 */
void data_types() {
  START

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

  END
}

/**
 * Sizeof common data types.
 */
void sizeof_data_types() {
  START

  // notice: sizeof is an operator
  printf("sizeof char:          %lu\n", sizeof(char));
  printf("sizeof short int:     %lu\n", sizeof(short int));
  printf("sizeof int:           %lu\n", sizeof(int));
  printf("sizeof float:         %lu\n", sizeof(float));
  printf("sizeof double:        %lu\n", sizeof(double));
  printf("sizeof long int:      %lu\n", sizeof(long int));
  printf("sizeof long long int: %lu\n", sizeof(long long int));
  printf("sizeof long double:   %lu\n", sizeof(long double));

  END
}

/**
 * Boolean type.
 */
void use_boolean_type() {
  START
  printf("include stdbool.h we can use true and false macros:\n");

  // include stdbool.h we can use true and false
  printf("true:  %d\n", true);
  printf("false: %d\n", false);

  END
}

/*
 * When overflow.
 */
void data_types_overflow() {
  START

  int maxInt = INT_MAX;
  int maxIntPlusOne = maxInt + 1;
  assert(maxIntPlusOne == INT_MIN);
  printf("int: %d + 1 = %d\n", maxInt, maxIntPlusOne);

  long maxLong = LONG_MAX;
  long maxLongPlusOne = maxLong + 1;
  printf("long: %ld + 1 = %ld\n", maxLong, maxLongPlusOne);
  assert(maxLongPlusOne == LONG_MIN);

  printf("\n");

  END
}

/**
 * Integer promotions.
 */
void integer_promotions() {
  START

  // sizeof(char) = 1Byte = 8 bit
  // the greatest value of a variable with char type is 127
  char a = 30, b = 40, c = 10;
  // a*b=1200 > 127
  char d = (a * b) / c;
  // still works - called integer promotion
  printf("((char)30) * ((char)40) / (char(10)) = %d\n", d);

  // e and f have same binary representation as char
  // so same character is printed
  // but when they are converted to int
  // signed char e becomes -5 (signed value of 0xfb)
  // unsigned char f becomes 251 (unsigned value of 0xfb)
  char e = 0xfb;
  unsigned char f = 0xfb;

  // (signed) char e (here, regarded as negative number): 1111 1011
  // Two's complement is the most common method of representing signed integers
  // on computers, which is calculated by inverting the digits and adding one.
  // so: if e is a 2's complement, the true value of e is:
  // 1111 1011 (2's complement)
  //        -1 (minus 1)
  // ----------
  // 1111 1010 (now inverse all numbers except the sign number)
  // ----------
  // 1000 0101 = -5

  // unsigned char f (regarded as positive numbers): 1111 1011
  // A positive number written in two's-complement notation is the same as
  // the number written in unsigned notation
  // so: f = 1111 1011(B) = 251(D)

  printf("((char)(0xfb)) = %c, ((int)(0xfb)) = %d\n", e, (int) e);
  printf("((unsigned char)(0xfb)) = %c, ((unsigned int)(0xfb)) = %d\n", f,
         (unsigned int) f);

  // when comparison operation is performed on e & f, they are first
  // converted to int.
  assert(e != f);

  END
}

int main(void) {
  data_types();
  use_boolean_type();
  sizeof_data_types();
  data_types_overflow();
  integer_promotions();

  return 0;
}