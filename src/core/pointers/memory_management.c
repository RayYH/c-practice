#include "core.h"

/**
 * malloc: memory allocation
 * calloc: contiguous allocation
 * free: de-allocate
 * realloc: re-allocation
 *
 * calloc() gives you a zero-initialized buffer, while malloc() leaves the memory uninitialized.
 */

void malloc_usage(int *ptr) {
  if (ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }
  for (int i = 0; i < 10; i++) {
    *(ptr + i) = rand() % 100;
  }
  for (int i = 0; i < 10; i++) {
    printf("%4d ", *(ptr + i));
  }
  printf("\n");
}

void realloc_usage(int *ptr) {
  ptr = realloc(ptr, 20 * sizeof(int));
  if (ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }
  for (int i = 0; i < 20; i++) {
    if (i % 10 == 0) {
      printf("\n");
    }
    printf("%4d ", *(ptr + i));
  }
  printf("\n");
}

void calloc_usage(int *ptr) {
  ptr = (int *) calloc(20, sizeof(int));
  if (ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }
  for (int i = 0; i < 20; i++) {
    if (i % 10 == 0) {
      printf("\n");
    }
    printf("%4d ", *(ptr + i));
  }
}

int main(void) {
  int *ptr = (int *) malloc(10 * sizeof(int));
  malloc_usage(ptr);
  realloc_usage(ptr);
  calloc_usage(ptr);
  free(ptr);

  return 0;
}
