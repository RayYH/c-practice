#include "std.h"
#include "stdlib.h"

/**
 * int rand (void); -- Generate random number.
 *
 * Returns a pseudo-random integral number in the range between 0 and RAND_MAX.
 */
void generate_random_values() {
  int v1 = rand() % 100;         // v1 in the range 0 to 99
  int v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
  int v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014

  printf("%d %d %d", v1, v2, v3);
}

// This program will create same sequence of random numbers on every program run.
int main(void) {
  generate_random_values();

  return 0;
}
