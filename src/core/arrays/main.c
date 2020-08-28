#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "assert.h"
#include "core.h"

/**
 * Traverse one-dimensional array.
 *
 * @param arr the location of given array
 * @param size the array size
 */
void traverse_one_dimensional_array(int *arr, int size);

/**
 * A simple example of array declaration.
 */
void array_declaration() {
  START

  // Array declaration by specifying size
  int arr1[10];
  for (int i = 0; i < 10; i++) {
    arr1[i] = 0;
  }

  traverse_one_dimensional_array(&arr1[0], 10);

  // With recent C/C++ versions, we can also
  // declare an array of user-specified size
  int array_size = 10;
  int arr2[array_size];
  for (int i = 0; i < array_size; i++) {
    arr2[i] = 0;
  }

  traverse_one_dimensional_array(&arr2[0], array_size);

  // Array declaration by initializing elements
  int arr3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  traverse_one_dimensional_array(
      &arr3[0],
      sizeof(arr3) / sizeof(int)
  );

  // Array declaration by specifying size and initializing elements
  int arr4[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  traverse_one_dimensional_array(&arr4[0], 10);

  END
}

/**
 * The elements are stored at contiguous memory locations.
 */
void contiguous_memory_locations() {
  int arr[5];
  for (int i = 0; i < 4; i++) {
    assert(
        ((long) &arr[i + 1] - (long) &arr[i]) == sizeof(int)
    );
  }
}

/**
 * Display one-dimensional array.
 */
void display_one_dimensional_array() {
  START

  int size = 5;
  int nums[5] = {12, 28, 3, 1, 9};

  assert ((sizeof(nums) / sizeof(nums[0])) == size);

  for (int i = 0; i < size; i++) {
    printf("nums[%d] is equal to %d\n", i, nums[i]);
  }

  END
}

/**
 * Display two-dimensional array.
 */
void display_two_dimensional_array() {
  START

  char ch[2][3] = {
      {'A', 'B', 'C'},
      {'D', 'E', 'F'}
  };

  assert ((sizeof(ch) / sizeof(ch[0])) == 2);
  assert ((sizeof(ch[0]) / sizeof(ch[0][0])) == 3);

  for (int i = 0; i < (sizeof(ch) / sizeof(ch[0])); i++) {
    for (int j = 0; j < (sizeof(ch[0]) / sizeof(ch[0][0])); j++) {
      printf("%c ", ch[i][j]);
    }
    printf("\n");
  }

  END
}

/**
 * Get inputs from stdin and save all elements to a fixed-size array.
 */
void array_from_stdin() {
  START

  int values[5];

  printf("\nEnter 5 integers (e.g. 1 2 3 4 5): ");
  for (int i = 0; i < 5; ++i) {
    scanf("%d", &values[i]);
  }

  printf("Displaying integers: ");
  for (int i = 0; i < 5; ++i) {
    printf("%d ", values[i]);
  }

  END
}

/**
 * A common one-dimensional array traversal method. If there's an array
 * `arr[i]`, the accepted params are:
 *
 * arr: &arr[0] or (int *) arr
 * size: i
 *
 * @param arr the first element's (or the array's) location
 * @param size size of array
 */
void traverse_one_dimensional_array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%-4d", *(arr + i));
  }

  printf("\n");
}

/**
 * A common two-dimensional array traversal method. If there's an array
 * `arr[i][j]`, the accepted params are:
 *
 * arr: &arr[0][0] or (int *) arr
 * outer_size: i
 * inner_size: j
 *
 * @param arr the first element's location
 * @param outer_size outer size
 * @param inner_size inner size
 */
void traverse_two_dimensional_array(int *arr, int outer_size, int inner_size) {
  for (int i = 0; i < outer_size; i++) {
    for (int j = 0; j < inner_size; j++) {
      printf("%-4d", *(arr + (i * inner_size) + j));
    }
    printf("\n");
  }

  printf("\n");
}

/**
 * a matrix addition example.
 */
void sum_square_matrix() {
  START

  int matrix_size = 5;
  int a[matrix_size][matrix_size];
  int b[matrix_size][matrix_size];
  time_t t;

  srand((unsigned) time(&t));

  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      a[i][j] = (rand() % (ELEM_MAX - ELEM_MIN + 1)) + ELEM_MIN;
      b[i][j] = (rand() % (ELEM_MAX - ELEM_MIN + 1)) + ELEM_MIN;
    }
  }

  printf("a: \n");
  traverse_two_dimensional_array((int *) a, matrix_size, matrix_size);
  printf("\nb: \n");
  traverse_two_dimensional_array((int *) b, matrix_size, matrix_size);
  printf("\na + b: \n");

  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      printf("%-4d", a[i][j] + b[i][j]);
    }

    printf("\n");
  }

  END
}

/**
 * Calculate the sum of elements from given array.
 *
 * @param f given array
 * @param size the size of array
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
  int arr[2][2] = {
      {1, 2},
      {3, 4}
  };
  display_numbers(arr);
  display_one_dimensional_array();
  display_two_dimensional_array();
  sum_square_matrix();
  not_certain_size_array();
  array_declaration();
  contiguous_memory_locations();
  array_from_stdin();

  return 0;
}