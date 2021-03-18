#include <stdlib.h>
#include <stdio.h>

int x;
int y = 15;

int main(void) {
  int *values;
  int i;

  values = (int *) malloc(sizeof(int) * 5);

  for (i = 0; i < 5; i++) {
    values[i] = i;
  }

  printf("y = %d\n", y);

  return 0;
}
