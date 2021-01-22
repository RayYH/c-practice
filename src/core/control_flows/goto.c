#include "core.h"

int main(void) {
  time_t t;
  srand((unsigned) time(&t));

  while (1) {
    int num = rand() % 100;

    printf("random number: %d\n", num);

    if (num < 30) {
      printf("less than 30, goto end...\n");
      goto end;
    }
  }

  end:
  printf(
      "The fact that 'goto' can do anything is exactly why we don't use it.\n"
  );

  return 0;
}
