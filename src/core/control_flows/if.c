#include "core.h"

int main(void) {
  time_t t;

  srand((unsigned) time(&t));
  int num = rand() % 100;

  if (num > 50) {
    if (num > 75) {
      printf("the number is greater than 75!\n");
    } else {
      printf("the number is greater than 50 and not greater than 75!\n");
    }
  } else if (num == 50) {
    printf("the number is equal to 50!\n");
  } else {
    printf("the number is less than 50!\n");
  }

  return 0;
}
