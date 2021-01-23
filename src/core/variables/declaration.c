#include "core.h"

// global variable
int z = 10;

int main(void) {
  // access global variable in current file
  assert(z == 10);
  z = 11;
  assert(z == 11);

  // access global variable defined in header file
  assert(global_int == 1);

  // local variable
  char b = 'G';
  assert(b == 'G');

  return 0;
}
