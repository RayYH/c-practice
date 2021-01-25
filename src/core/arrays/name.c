#include "core.h"

int main(void) {
  int doses[] = {1, 3, 2, 1000};
  // doses[3] == *(doses + 3) == *(3 + doses) == 3[doses]
  assert(3[doses] == 1000);
  int a[10];
  for (int i = 0; i < 10; i++) {
    a[i] = i;
  }

  for (int i = 0; i < 10; i++) {
    assert(i == i[a]);
  }
}
