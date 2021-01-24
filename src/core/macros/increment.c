#include "core.h"

#define INCREMENT(x) ++x

/**
 * The macros can take function like arguments, the arguments are not checked
 * for data type.
 */
int main(void) {
  char *str = "AbCdEf";
  int integer = 10;
  INCREMENT(str);
  INCREMENT(integer);
  assert(strcmp("bCdEf", str) == 0);
  assert(11 == integer);

  return 0;
}
