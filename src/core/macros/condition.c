#include "macros.h"

int main(void) {
  assert(MACRO_INTEGER_MAX == 100);
#if MACRO_INTEGER_MAX > 90
  printf("MACRO_INTEGER_MAX is greater than 90\n");
#endif

  return 0;
}
