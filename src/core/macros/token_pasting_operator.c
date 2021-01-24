#include "core.h"

#define CONCAT(a, b) a##b

int main(void) {
  assert(1234 == CONCAT(12, 34));
  assert(12.34 == CONCAT(12, .34));

  return 0;
}
