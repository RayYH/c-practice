#include "core.h"

/**
 * Simple function returns zero.
 *
 * @return constant 0
 */
int zero() {
  return 0;
}

int main(void) {
  int i = zero();
  assert((i ? 3 : 'A') == 65);
  assert((i ? 3 : 'A') == 'A');

  return 0;
}
