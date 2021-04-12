#include "core.h"

int main(void) {
  printf("include stdbool.h so we can use true and false macros:\n");
  bool is_true = true;
  bool is_false = false;
  printf("true:  %d\n", is_true);
  printf("false: %d\n", is_false);
}
