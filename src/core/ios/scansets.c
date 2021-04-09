#include "core.h"

int main(void) {
  char str[128];

  printf("Enter a string (e.g. RAY_HONG): ");
  scanf("%[A-Z]s", str); /* store only capital letters to array str. */
  printf("You entered: %s\n", str);
  fflush(stdin);

  char str2[128];
  printf("Enter a string (e.g. hello): ");
  scanf("%[^o]s", str2); /* read all characters but stops after first
                          * occurrence of `o` (o is not included). */
  printf("You entered: %s\n", str2);
  fflush(stdin);

  /* Never use gets - it is impossible to tell without knowing the data in
   * advance how many characters gets() will read, gets() will continue to
   * store characters past the end of the buffer, it is extremely
   * dangerous to use, use fgets instead. */

  char str3[128];
  printf("Enter a string with spaces (e.g. hello world): ");
  scanf("%[^\n]s", str3); /* implementation of gets() function using scanset. */
  printf("You entered: %s\n", str3);
  fflush(stdin);

  return 0;
}
