#include "sorting.h"

int partition(int *arr, int low, int high);
void quick_sort_recursive(int *arr, int low, int high);

void quick_sort(int *arr, int size) {
  quick_sort_recursive(arr, 0, size - 1);
}

void quick_sort_recursive(int *arr, int low, int high) {
  if (high <= low) {
    return;
  }
  int par = partition(arr, low, high);
  quick_sort_recursive(arr, low, par - 1);
  quick_sort_recursive(arr, par + 1, high);
}

int partition(int *arr, int low, int high) {
  int pivot = *(arr + low);
  int i = low;
  int j = high + 1;

  while (true) {
    while (*(arr + (++i)) < pivot) {
      if (i == high) {
        break;
      }
    }

    while (*(arr + (--j)) > pivot) {
      if (j == low) {
        break;
      }
    }

    if (i >= j) {
      break;
    }

    swap(arr, i, j);
  }

  swap(arr, low, j);

  return j;
}

int main(void) {
  int a[10] = {1, 2, 1000, 1, 5, 6, 7, 8, 11, 10};
  quick_sort(a, 10);
  assert(is_sorted(a, 10));
}
