#include "helper.h"
#include "sorting.h"

/**
 * Basic bubble sort.
 *
 * @param arr array to be sorted
 * @param size array size
 */
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}