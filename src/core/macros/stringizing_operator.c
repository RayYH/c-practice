#include "core.h"

/**
 * The # operator (known as the "Stringification Operator") converts a token
 * into a string, escaping any quotes or backslashes appropriately.
 *
 * If you want to stringify the expansion of a macro argument, you have to
 * use two levels of macros.
 */
#define xstr(s) str(s)
#define str(s) #s
#define foo bar

int main(void) {
  printf("%s\n", str(foo));
  printf("%s\n", xstr(foo));

  return 0;
}
