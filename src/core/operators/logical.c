#include "core.h"

void sizeof_logical_expression() {
  int x = 10, y = 10;
  assert(x == 10);
  assert(y == 10);
  // NOTE: in c++, sizeof(x == y) is 1
  assert(sizeof(x == y) == sizeof(int));
}

void basic_usage() {
  int c = 10, result;
  int a = c / 2;
  int b = c / 2;

  result = (a == b) && (c > b);
  printf("(a == b) && (c > b) is %d\n", result);
  result = (a == b) && (c < b);
  printf("(a == b) && (c < b) is %d\n", result);
  result = (a == b) || (c < b);
  printf("(a == b) || (c < b) is %d\n", result);
  result = (a != b) || (c < b);
  printf("(a != b) || (c < b) is %d\n", result);
  printf("!((a != b) || (c < b)) is %d\n", !result);
}

/**
 * Chaining of comparison operators.
 */
void chaining_of_comparison_operators() {
  // ( (3>2) <= 1 ) ==> ( 1 <= 1) ==> true
  assert(3 > 2 <= 1);
  // ( (3>2) <= 0 ) ==> ( 1 <= 0) ==> false
  assert(!(3 > 2 <= 0));
}

int main(void) {
  basic_usage();
  sizeof_logical_expression();
  chaining_of_comparison_operators();

  return 0;
}
