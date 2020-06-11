#include "helper.h"
#include "sorting.h"

/**
 * Basic bubble sort.
 *
 * @param arr array to be sorted
 * @param size array size
 */
void bubble_sort(int arr[], int size) {
    compare_num = 0;
    swap_num = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            compare_num++;
            if (arr[j] > arr[j + 1]) {
                swap_num++;
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubble_sort_with_flag(int arr[], int size) {
    bool swapped = TRUE;
    compare_num = 0;
    swap_num = 0;
    for (int i = 0; i < size - 1; i++) {
        if (!swapped) {
            break;
        }
        swapped = FALSE;
        for (int j = 0; j < size - 1 - i; j++) {
            compare_num++;
            if (arr[j] > arr[j + 1]) {
                swap_num++;
                swap(&arr[j], &arr[j + 1]);
                swapped = TRUE;
            }
        }
    }
}

void bubble_sort_with_flag_and_boundary(int arr[], int size) {
    bool swapped = TRUE;
    int lastIndex = size - 1;
    int end;
    compare_num = 0;
    swap_num = 0;
    for (int i = 0; i < size - 1; i++) {
        if (!swapped) {
            break;
        }
        swapped = FALSE;
        end = lastIndex;
        for (int j = 0; j < end; j++) {
            compare_num++;
            if (arr[j] > arr[j + 1]) {
                swap_num++;
                swap(&arr[j], &arr[j + 1]);
                swapped = TRUE;
                lastIndex = j;
            }
        }
    }
}