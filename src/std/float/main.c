#include "std.h"

#define pd(t, v) printf("%s: %d\n", t, v);
#define pe(t, v) printf("%s: %.5e\n", t, v);
#define ple(t, v) printf("%s: %.5Le\n", t, v);

void rounds() {
  START

  /*
   * 0 toward zero
   * 1 to nearest
   * 2 toward positive infinity
   * 3 toward negative infinity
   */
  pd("FLT_ROUNDS", FLT_ROUNDS)

  float a, b;
  a = 5.556f;
  b = -5.556f;
  switch (FLT_ROUNDS) {
    case 0: {
      printf("5.556 should be converted to 5.55: (float) a = %.2f\n", a);
      printf("-5.556 should be converted to -5.55: (float) b = %.2f\n", b);
      break;
    }
    case 1: {
      printf("5.556 should be converted to 5.56: (float) a = %.2f\n", a);
      printf("-5.556 should be converted to -5.56: (float) b = %.2f\n", b);
      break;
    }
    case 2: {
      printf("5.556 should be converted to 5.56: (float) a = %.2f\n", a);
      printf("-5.556 should be converted to -5.55: (float) b = %.2f\n", b);
      break;
    }
    case 3: {
      printf("5.556 should be converted to 5.55: (float) a = %.2f\n", a);
      printf("-5.556 should be converted to -5.56: (float) b = %.2f\n", b);
      break;
    }
    default: {
      break;
    }
  }

  END
}

int main(void) {
  rounds();

  // TODO

  return 0;
}
