#include "core.h"

#define MK_STR(s) #s

int main(void) {
  printf(MK_STR(hello world));

  return 0;
}
