#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helper.h"

void display(int arr[]) {
    int i;
    for (i = 0; i < ARRAY_NUM; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }

        printf("%-4d", arr[i]);
    }
}

void swap(int *first, int *second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

int *random_array() {
    static int res[ARRAY_NUM];
    time_t t;

    srand((unsigned) time(&t));

    for (int i = 0; i < ARRAY_NUM; i++) {
        res[i] = (rand() % (ELEM_MAX - ELEM_MIN + 1)) + ELEM_MIN;
    }

    return res;
}

void display_test() {
    int *arr = random_array();
    display(arr);
}

int *copy(int const *src) {
    int len = ARRAY_NUM;
    int *p = malloc(len * sizeof(int));
    memcpy(p, src, len * sizeof(int));
    return p;
}