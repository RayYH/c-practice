#include "core.h"

int main(void) {
  assert(3 % -8 == 3);
  assert(3 % 8 == 3);
  assert(-3 % 8 == -3);
  assert(-3 % -8 == -3);

  return 0;
}
