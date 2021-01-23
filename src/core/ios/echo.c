#include "core.h"

int main(void) {
  char *str = "Press Ctrl+Z (windows) or Ctrl+D (Linux/OSX) to exit this "
              "echo program.\n";
  // printf returns total number of Characters Printed
  assert(printf("%s", str) == strlen(str));

  printf(">>> ");
  // scanf returns total number of Inputs Scanned successfully,
  // return type of getchar(), fgetc() and getc() is int, not char
  // EOF is a minus int - usually `-1`
  int in;
  while ((in = getchar()) != EOF) {
    putchar(in);
    if (in == 0x0A) {
      printf(">>> ");
    }
  }

  return 0;
}
