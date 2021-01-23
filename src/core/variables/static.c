#include "core.h"

/**
 * Static variables are allocated memory in data segment, not stack segment.
 *
 * Static variables (like global variables) are initialized as 0 if not
 * initialized explicitly.
 *
 * In C, static variables can only be initialized using constant literals.
 * Static variables should not be declared inside structure.
 */
void static_variables() {
  int i = 0;
  while (i++ < 4) {
    // static variables will hold old values
    static int y = 5;
    y++;
    assert(y == 5 + i);
  }
}

/**
 * Counter with static keyword.
 *
 * @return the count
 */
static int static_counter() {
  static int count;
  count++;

  return count;
}

/**
 * Counter without static keyword.
 *
 * @return the count
 */
static int counter() {
  int count = 0;
  count++;
  return count;
}

int main(void) {
  static_variables();
  assert(counter() == 1);
  assert(counter() == 1);
  assert(static_counter() == 1);
  assert(static_counter() == 2);

  return 0;
}
