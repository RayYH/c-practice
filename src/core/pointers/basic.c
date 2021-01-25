#include "core.h"

int main(void) {
  int var = 5;
  int *p;
  p = &var;
  int *q = &var;

// variable location
  printf("address: %p\n", &var);
  printf("address: %p\n", p);
  printf("address: %p\n", q);

// access variables
  printf("value: %d\n", var);
  printf("value: %d\n", *p);
  printf("value: %d\n", *q);

// change value
  var = 10;
  printf("new value: %d\n", var);
  printf("new value: %d\n", *p);
  printf("new value: %d\n", *q);

  return 0;
}
