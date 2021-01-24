#include "macros.h"

int main(void) {
#undef MACRO_INTEGER_MAX
  int MACRO_INTEGER_MAX = 100;
  assert(MACRO_INTEGER_MAX == 100);

  return 0;
}
