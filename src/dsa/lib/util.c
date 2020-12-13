#include "sorting.h"

/**
 * Determine the elements of given array has already been sorted (ascending).
 *
 * @param array given array
 * @param size the size of array
 * @return true if sorted, otherwise false
 */
bool is_sorted(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    if (*(array + i) > *(array + i + 1)) {
      return false;
    }
  }

  return true;
}

/**
 * Swap two elements in a given array at specified indexes.
 *
 * @param array given array
 * @param i first index
 * @param j second index
 */
void swap(int *array, int i, int j) {
  int tmp = *(array + i);
  *(array + i) = *(array + j);
  *(array + j) = tmp;
}