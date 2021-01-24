#include "core.h"

#define PRINT(i, limit) while (i < limit) \
{ \
    printf("Hello World!\n"); \
    i++; \
}

int main(void) {
  int i = 0;
  PRINT(i, 3) // cannot use PRINT(0, 3);

  return 0;
}
