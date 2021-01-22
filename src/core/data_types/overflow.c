#include "core.h"

int main(void) {
  int maxInt = INT_MAX;
  int maxIntPlusOne = maxInt + 1;
  assert(maxIntPlusOne == INT_MIN);
  printf("int: %d + 1 = %d\n", maxInt, maxIntPlusOne);

  long maxLong = LONG_MAX;
  long maxLongPlusOne = maxLong + 1;
  printf("long: %ld + 1 = %ld\n", maxLong, maxLongPlusOne);
  assert(maxLongPlusOne == LONG_MIN);

  printf("\n");

  return 0;
}
