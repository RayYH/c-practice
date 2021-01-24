#include "core.h"

#define A -B
#define B -C
#define C 5

#define MULTIPLY(x, y) x*y
#define F MULTIPLY(1, 2)+3   // 1*2+3 = 5
#define E -F                 // -1*2+3 = 1
#define D -E                 // -- 1*2+3 = 1*2+3 = 5
#define G - -E               // --- 1*2+3 = -- -1*2+3 = -1*2+3 = 1
#define H - - - - - - - - - - - - - - -E // -- -- -- -- -- -- -- -E = D = 5

int main(void) {
  assert(A == 5);
  assert(D == 5);
  assert(E == 1);
  assert(F == 5);
  assert(G == 1);
  assert(H == 5);
  printf("A: %d\n", A);
  printf("D: %d\n", D);
  printf("E: %d\n", E);
  printf("F: %d\n", F);
  printf("G: %d\n", G);
  printf("G: %d\n", H);

  return 0;
}
