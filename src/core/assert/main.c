#include "assert.h"
#include "stdio.h"

/**
 * `assert.h` defines one macro function that can be used as a standard
 * debugging tool.
 *
 * @return 0
 */
int main(void) {
  int a = 10;
  int *b = NULL;
  int *c = NULL;
  b = &a;

  assert(b != NULL);
  assert(c == NULL);

  return 0;
}
