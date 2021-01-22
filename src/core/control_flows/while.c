#include "core.h"

/**
 * show while loop statements.
 */
void while_loop() {
  START

  int sum = 0, i = 1;
  while (i <= 10) {
    printf("%d ", i);
    sum += i;

    i++;
  }

  printf("\nsum: %d\n", sum);

  END
}

/**
 * Show do-while loop statements.
 */
void do_while_loop() {
  START

  int sum = 0, i = 1;
  do {
    printf("%d ", i);
    sum += i;
  } while (++i <= 10);

  printf("\nsum: %d\n", sum);

  END
}

int main(void) {
  while_loop();
  do_while_loop();

  return 0;
}
