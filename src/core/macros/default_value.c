#include "core.h"

#if X == 0
#define Y 5
#endif

int main(void) {
  // Y has been defined
  assert(Y == 5);
  return 0;
}
