#include "core.h"

enum week {
  Sunday,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
};

/**
 * Check given number via declared numbers.
 *
 * @param i given number
 */
void switch_enums(int i) {
  enum week today;
  today = i % 7;

  switch (today) {
    case Sunday:printf("Sunday!\n");
      break;
    case Monday:printf("Monday!\n");
      break;
    case Tuesday:printf("Tuesday!\n");
      break;
    case Wednesday:printf("Wednesday!\n");
      break;
    case Thursday:printf("Thursday!\n");
      break;
    case Friday:printf("Friday!\n");
      break;
    case Saturday:printf("Saturday!\n");
      break;
    default:printf("Invalid!");
      break;
  }
}

int main(void) {
  switch_enums(1);
  switch_enums(2);
  switch_enums(3);
  switch_enums(129);
  switch_enums(897);
  switch_enums(123);
  switch_enums(999);

  return 0;
}
