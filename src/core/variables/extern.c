#include "core.h"

int main(void) {
  extern int global_int;
  assert(global_int == 1);
  global_int = 10;
  assert(global_int == 10);
  global_int = 1;
  assert(global_int == 1);

  return 0;
}
