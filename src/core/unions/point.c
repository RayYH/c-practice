#include "core.h"

typedef union point {
  int x;
  int y;
} Point;

int main(void) {
  // use . when variable is of union type
  Point p;
  p.x = 2;
  assert(p.x == 2);
  assert(p.y == 2);

  // use -> when variable is a pointer to an union
  Point *ptr = &p;
  ptr->y = 10;
  assert(ptr->x == 10);
  assert(ptr->y == 10);
}
