#include "core.h"

int main(void) {
  int arr[5];
  for (int i = 0; i < 4; i++) {
    assert(((long) &arr[i + 1] - (long) &arr[i]) == sizeof(int));
  }
}
