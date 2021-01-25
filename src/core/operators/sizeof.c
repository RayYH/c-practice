#include "core.h"

void get_data_type_size() {
  int a = 0;
  double d = 10.21;
  assert(a + d > 0);
  assert(8 == sizeof(a + d));
}

void count_array_elements() {
  int arr[] = {1, 2, 3, 4, 7, 98, 0, 12, 35, 99, 14};
  int count = sizeof(arr) / sizeof(arr[0]);
  assert(11 == count);
  for (int i = 0; i < count; i++) {
    assert(arr[i] == *(arr + i));
  }
}

void allocate_memories() {
  int *ptr = (int *) malloc(10 * sizeof(int));
  free(ptr);
}

/**
 * The printf in sizeof is not executed only the return type of printf is
 * considered and its size is evaluated by sizeof.
 */
void used_with_printf() {
  int s = sizeof(printf("hey"));
  // printf returns value of int type
  assert(s == sizeof(int));
}

/**
 * Every string terminates with a NULL character (\0).
 */
void compare_to_strlen() {
  char str[] = "November";
  assert(strlen(str) == 8);
  assert(sizeof(str) == 9);

  // char array can be regarded as a string
  char arr1[] = {"Hello World"};
  char arr2[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
  char arr3[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};

  assert(sizeof(arr1) == 12); // 11 single char plus one NULL char
  assert(strlen(arr1) == 11); // 11 single char without ending NULL char

  // we dont know value of *(arr2+11), so the result of strlen is not certain
  assert(sizeof(arr2) == 11);
  assert(strlen(arr2) >= 11 * sizeof(char));
  printf("The ending char of arr2 array: %c", *(arr2 + 11));

  // manually add ending NULL char
  *(arr2 + 11) = '\0';
  assert(strlen(arr2) == 11 * sizeof(char));
  assert(strlen(arr3) == 11 * sizeof(char));
}

int main(void) {
  get_data_type_size();
  count_array_elements();
  allocate_memories();
  used_with_printf();
  compare_to_strlen();
}
