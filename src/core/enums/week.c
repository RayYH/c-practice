#include "core.h"

/**
 * If we do not explicitly assign values to enum names, the compiler by default
 * assigns values from 0. We can assign values to some name in any order. All
 * unassigned names get value as value of previous name plus one. The value
 * assigned to enum names must be a valid integer.
 */

enum week {
  sunday = 1,    // 1
  monday,        // 2
  tuesday = 5,   // 5
  wednesday,     // 6
  thursday = 10, // 10
  friday,        // 11
  saturday       // 12
};

int main(void) {
  assert(sunday == 1);
  assert(monday == 2);
  assert(tuesday == 5);
  assert(wednesday == 6);
  assert(thursday == 10);
  assert(friday == 11);
  assert(saturday == 12);

  return 0;
}
