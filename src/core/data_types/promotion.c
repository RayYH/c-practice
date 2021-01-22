#include "core.h"

int main(void) {
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

  return 0;
}
