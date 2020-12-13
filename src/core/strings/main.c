#include "core.h"

#define PRINT_STRING(str) printf("%s\n", str);

/**
 * The difference between a character array and a string is the string is
 * terminated with a special character ‘\0’.
 */
void initialize_a_string() {
  char str1[] = "Hello World!";
  PRINT_STRING(str1)
  char str2[50] = "Hello World!";
  PRINT_STRING(str2)
  char str3[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd',
                 '!', '\0'};
  PRINT_STRING(str3)
  char str4[13] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd',
                   '!', '\0'};
  PRINT_STRING(str4)
}

/**
 * Print a string.
 *
 * @param str string (an array of chars)
 */
void print_string(char str[]) {
  printf("String is : %s\n", str);
}

/**
 * Read string from stdin.
 */
void read_string_from_stdin() {
  char str[50];
  printf("Enter a string contains space: ");
  scanf("%s", str);
  print_string(str);

  printf("\n");
}

int main(void) {

  initialize_a_string();
  read_string_from_stdin();

  return 0;
}
