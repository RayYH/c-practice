#include "core.h"

#define PRINT_STRING(str) printf("%s\n", str);

/**
 * The difference between a character array and a string is the string is
 * terminated with a special character ‘\0’.
 */
int main(void) {
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

  return 0;
}
