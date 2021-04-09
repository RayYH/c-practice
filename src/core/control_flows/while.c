#include "core.h"

/**
 * While loop is executed only when given condition is true.
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
 * do-while loop is executed for first time irrespective of the condition.
 * After executing while loop for first time, then condition is checked.
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
