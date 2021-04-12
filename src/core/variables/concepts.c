#include "core.h"

void basic() {
  extern int i; // declaration
  /* If we assign value to i, we will encounter an error:
   * ld: symbol(s) not found for architecture x86_64 */

  int j; // definition
  /* Assignment is fine. */
  j = 1;

  double x = 3.14; // initialization
}

int main(void) {
  basic();

  return 0;
}
