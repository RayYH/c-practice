#include "core.h"

/**
 * Modulus on negative numbers.
 */
void modulus_on_negative_numbers() {
  int a = 3, b = -8, c = 2;
  // 3 % (-8) = (3 % 8) = 3
  assert(a % b == 3);
  b = 8;
  assert(a % b == 3);
  assert(a % b / c == 1);
  a = -3;
  b = 8;
  assert(a % b == -3);
  b = -8;
  assert(a % b == -3);
}

/**
 * printf returns the number of characters printed.
 *
 * @param x first number
 * @param y second number
 *
 * @return the number of characters printed.
 */
int add(int x, int y) {
  return printf("%*c%*c", x, '\r', y, '\r');
}

/**
 * Simple addition.
 *
 * @param a first number
 * @param b second number
 *
 * @return the addition of a & b.
 */
int addition(int a, int b) {
  if (b > 0) {
    while (b > 0) {
      a++;
      b--;
    }
  }
  if (b < 0) { // when 'b' is negative
    while (b < 0) {
      a--;
      b++;
    }
  }

  return a;
}

int main(void) {
  modulus_on_negative_numbers();
  assert(add(3, 4) == 7);
  assert(addition(3, 4) == 7);

  return 0;
}
