/** See also std/limits/main.c file. */
#include "core.h"

void sizes_assertions() {
  assert(sizeof(short) >= 2);
  assert(sizeof(int) >= 2);
  assert(sizeof(unsigned int) >= 2);
  assert(sizeof(long) >= 4);
  assert(sizeof(unsigned long) >= 4);
  assert(sizeof(long long) >= 8);
  assert(sizeof(unsigned long long) >= 8);
  assert(sizeof(char) == 1);
  assert(sizeof(signed char) == 1);
  assert(sizeof(unsigned char) == 1);
  assert(sizeof(float) == 4);
  assert(sizeof(double) == 8);
  assert(sizeof(long double) >= 10);
}

void format_specifiers() {
  short a_short = -1;
  int an_int = -2;
  unsigned int an_unsigned_int = 3;
  long a_long = -4L;
  unsigned long an_unsigned_long = 5l;
  long long a_long_long = -6;
  unsigned long long an_unsigned_long_long = 7;
  char a_char = '8';
  signed char a_signed_char = '9';
  unsigned char an_unsigned_char = 'a';
  float a_float = 11.0f;
  double a_double = 12.0;
  long double a_long_double = 13.0;
  printf("a_short: %hd\n", a_short);
  printf("an_int: %d\n", an_int);
  printf("an_unsigned_int: %u\n", an_unsigned_int);
  printf("a_long: %ld\n", a_long);
  printf("an_unsigned_long: %lu\n", an_unsigned_long);
  printf("a_long_long: %lld\n", a_long_long);
  printf("an_unsigned_long_long: %llu\n", an_unsigned_long_long);
  printf("a_char: %c\n", a_char);
  printf("a_signed_char: %c\n", a_signed_char);
  printf("an_unsigned_char: %c\n", an_unsigned_char);
  printf("a_float: %f\n", a_float);
  printf("a_double: %lf\n", a_double);
  printf("a_long_double: %Lf\n", a_long_double);
}

int main(void) {
  sizes_assertions();
  format_specifiers();

  return 0;
}
