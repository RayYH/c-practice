#include "core.h"

int main(void) {
  time_t t;
  srand((unsigned) time(&t));

  while (1) {
    int num = rand() % 100;
    printf("random number: %d\n", num);

    if (num < 30) {
      printf("less than 30, break...\n");
      break;
    }

    if (num > 70) {
      printf("greater than 70: continue..\n");
      continue;
    }
  }

  return 0;
}
