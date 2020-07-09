#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void if_condition() {
    time_t t;

    srand((unsigned) time(&t));
    int num = rand() % 100;

    if (num > 50) {
        // nested if
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

    printf("\n");
}

void for_loop() {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
        sum += i;
    }

    printf("\nsum: %d\n\n", sum);
}

void while_loop() {
    int sum = 0, i = 1;
    while (i <= 10) {
        printf("%d ", i);
        sum += i;

        i++;
    }

    printf("\nsum: %d\n\n", sum);
}

void do_while_loop() {
    int sum = 0, i = 1;
    do {
        printf("%d ", i);
        sum += i;
    } while (++i <= 10);

    printf("\nsum: %d\n\n", sum);
}

void break_continue() {
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

    printf("\n");
}

// https://www.programiz.com/c-programming/c-switch-case-statement
void switch_case() {
    char operator;
    double n1, n2;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &n1, &n2);

    switch (operator) {
        case '+':
            printf("%.1lf + %.1lf = %.1lf", n1, n2, n1 + n2);
            break;

        case '-':
            printf("%.1lf - %.1lf = %.1lf", n1, n2, n1 - n2);
            break;

        case '*':
            printf("%.1lf * %.1lf = %.1lf", n1, n2, n1 * n2);
            break;

        case '/':
            printf("%.1lf / %.1lf = %.1lf", n1, n2, n1 / n2);
            break;

        default:
            printf("Error! operator is not correct");
    }
    printf("\n");
}


void goto_statement() {
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
    printf("The fact that 'goto' can do anything is exactly why we don't use it.\n\n");
}

int main(void) {
    if_condition();
    for_loop();
    while_loop();
    do_while_loop();
    break_continue();
    goto_statement();
    switch_case();

    return 0;
}