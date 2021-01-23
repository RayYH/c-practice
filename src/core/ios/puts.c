#include "core.h"

int main(void) {
  printf("Using puts: \n");
  puts("Hello ");
  puts("World");
  printf("\nUsing fputs: \n");
  fputs("Hello ", stdout);
  fputs("World", stdout);
}
