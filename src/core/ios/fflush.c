#include "core.h"

int main(void) {
  // it is not recommended to use it as it is undefined behavior by
  // language standard.
  char str[20];
  int i;
  printf("Enter a string: ");
  for (i = 0; i < 2; i++) {
    scanf("%[^\n]s", str);
    printf("%s\n", str);
  }

  printf("\nEnter a string: ");
  fflush(stdin);
  for (i = 0; i < 2; i++) {
    scanf("%[^\n]s", str);
    printf("%s\n", str);
    fflush(stdin);
  }
}
