#include "core.h"

/**
 * To use rest parameters, you should include `stdarg.h` header file first.
 *
 * 1. Define a function with its last parameter as ellipses and the one just
 *    before the ellipses is always an `int` which will represent the number
 *    of arguments.
 * 2. Create a `va_list` type variable in the function definition.
 * 3. Use `int` parameter and `va_start` macro to initialize the `va_list`
 *    variable to an argument list.
 * 4. Use `va_arg` macro and `va_list` variable to access each item in argument
 *    list.
 * 5. Use a macro `va_end` to clean up the memory assigned to `va_list` variable.
 */
double average(int num, ...) {
  va_list variable_list;
  double sum = 0.0;
  int i;
  va_start(variable_list, num);

  for (i = 0; i < num; i++) {
    sum += va_arg(variable_list, int);
  }
  va_end(variable_list);

  return sum / num;
}

int main(void) {
  assert(average(4, 2, 3, 4, 5) == 3.5);
  assert(average(3, 5, 10, 15) == 10.0);

  return 0;
}
