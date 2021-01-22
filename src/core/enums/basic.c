#include "core.h"

/**
 *******************************************************************************
 * Enums vs Macros
 * ==> 1. Enums follow scope rules.
 * ==> 2. Enum variables are automatically assigned values.
 *******************************************************************************
 */

enum state {
  Working = 1,
  Failed = 0,
  Frozen = 0 // Two enum names can have same value.
};

int main(void) {
  // define a variable which can be assigned an enum
  enum state current_state = Working;
  assert(current_state == 1);

  // we can use enum names directly
  assert(Working == 1);
  assert(Failed == 0);
  assert(Frozen == 0);

  return 0;
}
