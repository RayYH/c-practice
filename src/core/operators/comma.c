#include "core.h"

#define parenthesis (one, two, three);
#define no_parenthesis one, two, three;

int g_var = 0;

/**
 * change g_var to 5.
 *
 * @return g_var
 */
int assign_5_to_g_var() {
  g_var = 5;
  return g_var;
}

/**
 * change g_var to 10.
 *
 * @return g_var
 */
int assign_10_to_g_var() {
  g_var = 10;
  return g_var;
}

/**
 * The comma operator is a binary operator that evaluates its first operand and discards the result,
 * it then evaluates the second operand and returns this value (and type).
 *
 * @return
 */
void comma_as_an_operator() {
  assert(10 == (assign_5_to_g_var(), assign_10_to_g_var()));

  int z = 10;
  int y = (z++, ++z);
  assert(y == 12);
  assert(z == 12);

  z = 10;
  int y_2 = (z++, z++);
  assert(y_2 == 11);
  assert(z == 12);

  z = 10;
  int y_3 = (z++, ++z, z++);
  assert(y_3 == 12);
  assert(z == 13);

  z = 10;
  int y_4 = (z++, z++, ++z);
  assert(y_4 == 13);
  assert(z == 13);
}

void comma_with_parenthesis() {
  int one = 1, two = 2, three = 3;
  int a;
  a = no_parenthesis
  assert(a == one);
  a = parenthesis
  assert(a == three);
}

int main(void) {
  comma_as_an_operator();
  comma_with_parenthesis();

  return 0;
}
