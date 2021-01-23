#include "core.h"

union u_1 {
  int x;
  int y;
} U1;

union u_2 {
  int x;
  char y;
} U2;

union u_3 {
  int x[10];
  char y;
} U3;

void share_memory_location() {
  assert(sizeof(U1) == sizeof(int));
  assert(sizeof(U2) == sizeof(int));
  assert(sizeof(U3) == sizeof(int) * 10);
}

void access_elements() {
  union u_1 u1;
  u1.x = 0;
  assert(u1.x == 0);
  assert(u1.y == 0);
  u1.y = 1;
  assert(u1.x == 1);
  assert(u1.y == 1);

  union u_2 u2;
  u2.x = 65;
  assert(u2.x == 65);
  assert(u2.y == 'A');

  union u_3 u3;
  u3.x[0] = 65;
  assert(u3.x[0] == 65);
  assert(u3.y == 'A');
}

int main(void) {
  share_memory_location();
  access_elements();

  return 0;
}
