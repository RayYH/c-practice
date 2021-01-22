#include "core.h"

/**
 * A general method for iterating one-dimensional array.
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

/**
 * A common two-dimensional array traversal method.
 *
 * @param arr           the first element's location
 * @param outer_size    outer size
 * @param inner_size    inner size
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
 * A matrix addition example.
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
  traverse_one_dimensional_array(&values[0], 5);

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

int main(void) {
  array_from_stdin();
  sum_square_matrix();
  display_two_dimensional_array();

  return 0;
}
