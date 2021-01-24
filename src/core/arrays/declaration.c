#include "core.h"

/**
 * Iterating one-dimensional array.
 *
 * HINT: there's no difference between `int *arr` and `int arr[]`.
 *
 * @param arr   pointer to given array
 * @param size  size of given array
 */
void traverse_one_dimensional_array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%-4d", *(arr + i));
  }

  printf("\n");
}

int main(void) {
  // array declaration with specified size
  int arr1[10];
  for (int i = 0; i < 10; i++) {
    arr1[i] = 0;
  }
  traverse_one_dimensional_array(&arr1[0], 10);

  // with recent C/C++ versions, we can also
  // declare an array of user-specified size
  int array_size = 10;
  int arr2[array_size];
  for (int i = 0; i < array_size; i++) {
    arr2[i] = 0;
  }
  // instead of passing &arr2[0] (the first element's location)
  // we pass the array name - arr2, which has the same effect
  traverse_one_dimensional_array(arr2, array_size);

  // array declaration with initialized elements
  int arr3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  traverse_one_dimensional_array(&arr3[0], sizeof(arr3) / sizeof(int));

  // array declaration by specifying size and initializing elements
  int arr4[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  traverse_one_dimensional_array(arr4, 10);

  return 0;
}
