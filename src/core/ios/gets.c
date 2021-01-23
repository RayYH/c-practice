#include "core.h"

int main(void) {
  char str[4];
  printf("Enter a string (e.g. something): ");
  fgets(str, 4, stdin);
  // if you entered 'something', you'll get 'som' instead of 'some'
  printf("You entered: %s\n", str);
  fflush(stdin);
}
