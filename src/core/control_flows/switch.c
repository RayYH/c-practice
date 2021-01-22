#include "core.h"

/**
 * Show switch-case statements.
 *
 * @param operator  given operator + - * /
 * @param n1        first value
 * @param n2        second value
 */
void switch_case(char operator, double n1, double n2) {
  switch (operator) {
    case '+':printf("%.1lf + %.1lf = %.1lf\n", n1, n2, n1 + n2);
      break;

    case '-':printf("%.1lf - %.1lf = %.1lf\n", n1, n2, n1 - n2);
      break;

    case '*':printf("%.1lf * %.1lf = %.1lf\n", n1, n2, n1 * n2);
      break;

    case '/':printf("%.1lf / %.1lf = %.1lf\n", n1, n2, n1 / n2);
      break;

    default:printf("Error! operator %c is not supported yet", operator);
  }

}

int main(void) {
  switch_case('+', 4.0, 2.0);
  switch_case('-', 4.0, 2.0);
  switch_case('*', 4.0, 2.0);
  switch_case('/', 4.0, 2.0);
  switch_case('^', 4.0, 2.0);

  return 0;
}
