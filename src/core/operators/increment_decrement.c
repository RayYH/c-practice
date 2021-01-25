#include "core.h"

int main(void) {
  int a = 10, b = 100;
  float c = 10.5f, d = 100.5f;

  ++a;
  --b;
  ++c;
  --d;
  printf("++a = %d \n", a);
  printf("--b = %d \n", b);
  printf("++c = %f \n", c);
  printf("--d = %f \n", d);

  return 0;
}
