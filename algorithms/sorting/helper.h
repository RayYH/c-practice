#ifndef C_PRACTICE_HELPER_H
#define C_PRACTICE_HELPER_H

#define ARRAY_NUM 100
#define ELEM_MIN 0
#define ELEM_MAX 200

#define TRUE 1
#define FALSE 0

typedef int bool;

int compare_num;
int swap_num;

void display_test();

void display(int arr[]);

int *random_array();

void swap(int *first, int *second);

int *copy(const int arr[]);

#endif //C_PRACTICE_HELPER_H