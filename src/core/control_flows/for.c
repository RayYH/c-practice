#include "core.h"

int main(void) {
  int sum = 0;
  for (int i = 1; i <= 10; i++) {
    printf("%d ", i);
    sum += i;
  }

  printf("\nsum: %d\n", sum);

  return 0;
}
