#include "macros.h"
#include "core.h"

static inline int square(int x) { return x * x; }

void std_macro_usage() {
  START

  // https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html
  printf("__DATE__: %s\n", __DATE__);
  printf("__TIME__: %s\n", __TIME__);
  printf("__FILE__: %s\n", __FILE__);
  printf("__LINE__: %d\n", __LINE__);
  printf("__STDC__: %d\n", __STDC__);
  printf("__STDC_VERSION__: %ld\n", __STDC_VERSION__);
  printf("__STDC_HOSTED__: %d\n", __STDC_HOSTED__);

  END
}

void custom_macro_usage() {
  START

  assert(MACRO_INTEGER_MAX == 100);
  // you can redefine a macro, compiler will not throw an error
  //#define MACRO_INTEGER_MAX 101
  //    assert(MACRO_INTEGER_MAX == 101);
  char *str = "AbCdEf";
  int integer = 10;
  INCREMENT(str);
  INCREMENT(integer);
  assert(strcmp("bCdEf", str) == 0);
  assert(11 == integer);
  assert(6 == MULTIPLY(2, 3));
  assert(16 == MULTIPLY(2 + 3, 3 + 5)); // 2+3*3+5 = 2+9+5 = 16
  assert(40 == MULTIPLY2(2 + 3, 3 + 5)); // (2+3)*(3+5) = 40
  assert(1234 == MERGE(12, 34));

  printf("%s!\n", GET(C PRACTICE));

  int i = 0;
  // cannot use PRINT(0, 3);
  PRINT(i, 3)

  int x = 36 / SQUARE(6); // is equivalent to 36/6*6
  assert(x == 36);
  assert(1 == 36 / square(6));
#if MACRO_INTEGER_MAX > 90
  printf("MACRO_INTEGER_MAX is greater than 90\n");
#endif
  // remove macro
#undef MACRO_INTEGER_MAX
  int MACRO_INTEGER_MAX = 100;
  assert(MACRO_INTEGER_MAX == 100);
  assert(Y == 5);
  assert(A == 5);
  int m = 4;
  assert(SQUARE(m + 2) == 14); // m+2*m+2 = m+2m+2 = 3m+2 = 14
  printf("A: %d\n", A);
  printf("D: %d\n", D);
  printf("- -1 * 2 + 3: %d\n", - -1 * 2 + 3);
  printf("E: %d\n", E);
  printf("-1 * 2 + 3: %d\n", -1 * 2 + 3);
  printf("F: %d\n", F);
  printf("G: %d\n", G);

  END
}

int main(void) {

  std_macro_usage();
  custom_macro_usage();

  return 0;
}