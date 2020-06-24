#include "array.h"

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }

        printf("%4d ", arr[i]);
    }
}

