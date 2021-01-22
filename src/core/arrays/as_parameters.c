#include "core.h"

/**
 * Calculate the sum of elements from given array.
 *
 * float f[] means float *f, a pointer to a float value.
 *
 * @param   f       given array
 * @param   size    the size of array
 *
 * @return the sum of array elements
 */
double calculate_sum(float f[], int size) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += f[i];
  }

  return sum;
}

/**
 * We can use `sizeof` operator to get the size of size-not-certain array.
 */
void not_certain_size_array() {
  START

  float f[] = {23.4, 55, 22.6, 3, 40.5, 18};
  int size = (sizeof(f) / sizeof(float));
  for (int i = 0; i < size; i++) {
    printf("%.2f ", f[i]);
  }

  printf("\nsum: %f\n", calculate_sum(f, size));

  END
}

/**
 * We can pass a whole array instead of a pointer to a function.
 *
 * In fact, as long as the parameter holds the int value, no compilation error
 * will throw. For example, display_numbers(1);
 *
 * @param num array
 */
void display_numbers(int num[2][2]) {
  START

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      printf("%d ", num[i][j]);
    }

    printf("\n");
  }

  END
}

int main(void) {
  not_certain_size_array();
  int arr[2][2] = {
      {1, 2},
      {3, 4}
  };
  display_numbers(arr);

  return 0;
}
