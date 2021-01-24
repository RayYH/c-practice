#include "core.h"

#define SQUARE(x) x*x
static inline int square(int x) { return x * x; }

int main(void) {
  int x = 36 / SQUARE(6); // is equivalent to 36/6*6
  assert(x == 36);
  assert(1 == 36 / square(6));
  int m = 4;
  assert(SQUARE(m + 2) == 14); // m+2*m+2 = m+2m+2 = 3m+2 = 14

  return 0;
}
