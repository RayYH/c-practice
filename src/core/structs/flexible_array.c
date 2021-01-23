#include "core.h"

/**
 * In gcc, when we create an array of zero length, it is considered as array
 * of incomplete type that’s why gcc reports its size as “0” bytes.
 *
 * When we create array of zero length inside structure, it must be (and only)
 * last member of structure.
 */

struct IntContainer {
  int base;
  int list[];
};

struct CharContainer {
  char base;
  char list[0];
};

int main(void) {
  assert(sizeof(struct IntContainer) == sizeof(int));
  assert(sizeof(struct CharContainer) == sizeof(char));

  struct IntContainer ic;
  ic.base = 1;
  int *ic_ptr = ic.list;
  *(ic_ptr) = 2;
  *(ic_ptr + 1) = 3;
  assert(ic.base == 1);
  assert(ic.list[0] == 2);
  assert(ic.list[1] == 3);

  struct CharContainer cc;
  cc.base = 'A';
  char *cc_ptr = cc.list;
  *(cc_ptr) = 'B';
  *(cc_ptr + 1) = 'C';
  assert(cc.base == 'A');
  assert(cc.list[0] == 'B');
  assert(cc.list[1] == 'C');

  return 0;
}
