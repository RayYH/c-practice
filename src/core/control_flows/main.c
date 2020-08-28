#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "core.h"

/**
 * Show if-elseif-else condition statements.
 */
void if_condition() {
  START

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

  END
}

/**
 * Show for loop statements.
 */
void for_loop() {
  START

  int sum = 0;
  for (int i = 1; i <= 10; i++) {
    printf("%d ", i);
    sum += i;
  }

  printf("\nsum: %d\n", sum);

  END
}

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

/**
 * Show break and continue statements.
 */
void break_continue() {
  START

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

  END
}

/**
 * Show switch-case statements.
 *
 * @param operator given operator + - * /
 * @param n1 number1
 * @param n2 number2
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

void switch_case_test() {
  START

  switch_case('+', 4.0, 2.0);
  switch_case('-', 4.0, 2.0);
  switch_case('*', 4.0, 2.0);
  switch_case('/', 4.0, 2.0);
  switch_case('^', 4.0, 2.0);

  END
}

/**
 * Show goto statements.
 */
void goto_statement() {
  START

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

  END
}

int main(void) {
  if_condition();
  for_loop();
  while_loop();
  do_while_loop();
  break_continue();
  goto_statement();
  switch_case_test();

  return 0;
}