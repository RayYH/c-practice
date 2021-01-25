#include "core.h"

int main(void) {
  int x[4], i;

  for (i = 0; i < 4; i++) {
    printf("&x[%d] = %p\n", i, &x[i]);
  }

  printf("Address of array x: %p\n", x);

  int y[5] = {1, 2, 3, 4, 5};
  int *ptr;

  // ptr is assigned the address of the third element
  ptr = &y[2];
  printf("*ptr = %d \n", *ptr);           // 3
  printf("*(ptr+1) = %d \n", *(ptr + 1)); // 4
  printf("*(ptr-1) = %d", *(ptr - 1));    // 2

  return 0;
}
