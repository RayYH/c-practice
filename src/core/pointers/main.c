#include "core.h"

/**
 * Pointers can be used for getting a variable's address.
 */
void pointers_usage() {
  START

  int var = 5;
  int *p;
  p = &var;
  int *q = &var;

  // variable location
  printf("address: %p\n", &var);
  printf("address: %p\n", p);
  printf("address: %p\n", q);

  // access variables
  printf("value: %d\n", var);
  printf("value: %d\n", *p);
  printf("value: %d\n", *q);

  // change value
  var = 10;
  printf("new value: %d\n", var);
  printf("new value: %d\n", *p);
  printf("new value: %d\n", *q);

  END
}

/**
 * arr[] is a pointer, so arr[i] equals to *(arr+i).
 */
void pointers_with_arrays() {
  START

  int x[4];
  int i;

  for (i = 0; i < 4; i++) {
    printf("&x[%d] = %p\n", i, &x[i]);
  }

  printf("Address of array x: %p\n", x);

  int y[5] = {1, 2, 3, 4, 5};
  int *ptr;

  // ptr is assigned the address of the third element
  ptr = &y[2];

  printf("*ptr = %d \n", *ptr);   // 3
  printf("*(ptr+1) = %d \n", *(ptr + 1)); // 4
  printf("*(ptr-1) = %d", *(ptr - 1));  // 2

  END
}

/**
 * Some function can be used for managing memory allocation.
 */
void memory_usage() {
  START

  int *ptr = (int *) malloc(10 * sizeof(int));

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

  free(ptr);

  END
}

/**
 * A trick example.
 */
void pointer_trick() {
  int doses[] = {1, 3, 2, 1000};
  // doses[3] == *(doses + 3) == *(3 + doses) == 3[doses]
  assert(3[doses] == 1000);
  int a[10];
  for (int i = 0; i < 10; i++) {
    a[i] = i;
  }

  for (int i = 0; i < 10; i++) {
    assert(i == i[a]);
  }
}

/**
 * Pointers can be used for addition and subtraction.
 */
void plus_pointer() {
  char carr[] = "hello";
  char *p = carr;
  ++*p;
  // 'h' ++
  assert((*p) == 'i');
  assert(*p++);
  assert((*p) == 'e');

  int arr1[] = {10, 20};
  int arr2[] = {10, 20};
  int arr3[] = {10, 20};
  int *p1 = arr1;
  int *p2 = arr2;
  int *p3 = arr3;

  // ++(*p1)
  ++*p1;
  assert(arr1[0] == 11);
  assert(arr1[1] == 20);
  assert(*p1 == 11);


  // *p2++ =  *(p2++)
  p2++;
  assert(arr2[0] == 10);
  assert(arr2[1] == 20);
  assert(*p2 == 20);

  // *++p3 = *(++p3)
  ++p3;
  assert(arr3[0] == 10);
  assert(arr3[1] == 20);
  assert(*p3 == 20);
}

int main(void) {
  pointers_usage();
  pointers_with_arrays();
  pointer_trick();
  plus_pointer();
  memory_usage();

  return 0;
}
