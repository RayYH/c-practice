#include "core.h"

/**
 * Print a string.
 *
 * @param str string (an array of chars)
 */
void print_string(char str[]) {
  printf("String is : %s\n", str);
}

/**
 * Read string from stdin.
 */
int main(void) {
  char str[50];
  printf("Enter a string contains space (e.g. Hello World): ");
  scanf("%s", str);
  print_string(str);

  return 0;
}
