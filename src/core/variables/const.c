#include "core.h"

/**
 * Constant variables must be initialized during their declaration.
 * const keyword is also used with pointers.
 *
 * Important rule: read it BACKWARDS.
 *
 * int* - pointer to int
 * int const * - pointer to const int
 * int * const - const pointer to int
 * int const * const - const pointer to const int
 *
 * the first const can be on either side of the type so:
 * const int * == int const *
 * const int * const == int const * const
 *
 * And more:
 * int ** - pointer to pointer to int
 * int ** const - a const pointer to a pointer to an int
 * int * const * - a pointer to a const pointer to an int
 * int const ** - a pointer to a pointer to a const int
 * int * const * const - a const pointer to a const pointer to an int
 *
 * if the const keyword appears in the left part (like in 'const int * foo')
 *     - it belongs to pointed data
 * if it's in the right part ('int * const bar')
 *     - it's about the pointer
 * @see https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
 */
int main(void) {
  // i is a int constant
  const int i = 10;
  // i = 11; -> error
  assert(i == 10);

  int j = 20;
  // p is a pointer to const int (const int * == int const *)
  // also, const is at the left part of symbol *, so it's about the data
  const int *p = &j;
  assert((*p) == 20);

  // we cannot change value by pointer like this: *p = 100;
  // but we can change p - (since p is not a constant)
  int k = 30;
  p = &k;
  assert((*p) == 30);

  // a const pointer to a const int
  // const occurs at both left and right part of the * symbol
  // it's about both data and pointer
  const int *const ptr = &i;
  assert((*ptr) == 10);
  // ptr = &j;    -> error
  // *ptr = 100;  -> error

  return 0;
}
