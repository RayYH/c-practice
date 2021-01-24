#include "core.h"

#define WRONG_MULTIPLY(x, y) x*y
#define CORRECT_MULTIPLY(a, b) ((a)*(b))

int main(void) {
  assert(6 == WRONG_MULTIPLY(2, 3));
  assert(16 == WRONG_MULTIPLY(2 + 3, 3 + 5)); // 2+3*3+5 = 2+9+5 = 16
  assert(40 == CORRECT_MULTIPLY(2 + 3, 3 + 5)); // (2+3)*(3+5) = 40

  return 0;
}
