#include "core.h"

/**
 * `void` is considered a data type (for organizational purposes), but it is
 * basically a keyword to use as a placeholder where you would put a data
 * type, to represent "no data".
 */
int main(void) {
  // malloc() and calloc() return void * type and this allows these functions
  // to be used to allocate memory of any data type
  int a = 10;
  char b = 'b';

  void *p = &a;
  assert(*(int *) (p) == 10);

  p = &b;
  assert(*(char *) (p) == 'b');

  int c[2] = {1, 2};
  void *ptr = &c;
  ptr = ptr + sizeof(int);
  // only in GNU C
  assert(*(int *) ptr == 2);

  return 0;
}
