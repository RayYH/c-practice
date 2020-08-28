#include "assert.h"
// In union, all members share the same memory location.

typedef union point {
  int x;
  int y;
} Point;

union test1 {
  int x;
  int y;
} Test1;

union test2 {
  int x;
  char y;
} Test2;

union test3 {
  int arr[10];
  char y;
} Test3;

union test {
  int x;
  char y;
};

void avoid_inspection() {
  union test1 test_1;
  test_1.x = 0;
  assert(test_1.x == 0);
  test_1.y = 0;
  assert(test_1.y == 0);
  union test2 test_2;
  test_2.x = 0;
  assert(test_2.x == 0);
  test_2.y = 'A';
  assert(test_2.y == 'A');
  // all members share the same memory location.
  // so in below code, arr[0] = y = 'A'
  union test3 test_3;
  test_3.arr[0] = 'A';
  assert(test_3.arr[0] == 'A');
  assert(test_3.y == 'A');
}

void share_same_location() {
  Point p;
  p.x = 2;
  assert(p.x == 2);
  assert(p.y == 2);
  p.y = 10;
  assert(p.x == 10);
  assert(p.y == 10);

  assert(sizeof(Test1) == 4);
  assert(sizeof(Test2) == 4);
  assert(sizeof(Test3) == 40);
}

void union_with_pointer() {
  union test p1;
  p1.x = 65;
  // p2 is a pointer to union p1
  union test *p2 = &p1;
  assert(p2->x == 65);
  assert(p2->y == 65);
}

int main(void) {

  avoid_inspection();
  share_same_location();
  union_with_pointer();

  return 0;
}