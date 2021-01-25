#include "core.h"

int main(void) {
  int a = 4;
  int b = 10;
  a > b || printf("a < b\n");
  b > a && printf("b > a\n");

  return 0;
}
