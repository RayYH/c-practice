#include "core.h"

/**
 * %n is a special format specifier.
 *
 * It cause printf() to load the variable pointed by corresponding argument.
 * The loading is done with a value which is equal to the number of characters
 * printed by printf() before the occurrence of %n.
 */
int main(void) {
  int c;
  // equals to the length of "my name is "
  printf("my name is %nray!", &c);
  assert(c == 11);

  return 0;
}
