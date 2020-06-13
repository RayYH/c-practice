#include "arrays.h"

void simple_array() {
    int nums[5] = {12, 28, 3, 1, 9};

    for (int i = 0; i < (sizeof(nums) / sizeof(int)); i++) {
        printf("nums[%d] is equal to %d\n", i, nums[i]);
    }
}

void input_output() {
    int values[5];

    printf("\nEnter 5 integers: ");
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &values[i]);
    }

    printf("Displaying integers: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", values[i]);
    }

    printf("\n");
}

void multi_dimensional_array() {
    char ch[2][3] = {
            {'A', 'B', 'C'},
            {'D', 'E', 'F'}
    };

    for (int i = 0; i < (sizeof(ch) / sizeof(ch[0])); i++) {
        for (int j = 0; j < (sizeof(ch[0]) / sizeof(ch[0][0])); j++) {
            printf("%c ", ch[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void display_two_dimensional_array(int *arr, int outer_size, int inner_size) {
    for (int i = 0; i < outer_size; i++) {
        for (int j = 0; j < inner_size; j++) {
            printf("%-4d", *(arr + (i * inner_size) + j));
        }

        printf("\n");
    }
}

void sum_square_matrix() {
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
    display_two_dimensional_array((int *) a, matrix_size, matrix_size);
    printf("\nb: \n");
    display_two_dimensional_array((int *) b, matrix_size, matrix_size);
    printf("\na + b: \n");

    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            printf("%-4d", a[i][j] + b[i][j]);
        }

        printf("\n");
    }
}

double calculate_sum(float f[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += f[i];
    }

    return sum;
}

void not_certain_size_array() {
    float f[] = {23.4, 55, 22.6, 3, 40.5, 18};
    int size = (sizeof(f) / sizeof(float));
    for (int i = 0; i < size; i++) {
        printf("%.2f ", f[i]);
    }

    printf("\nsum: %f", calculate_sum(f, size));
}

void display_numbers(int num[2][2]) {
    printf("Displaying:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d ", num[i][j]);
        }

        printf("\n");
    }
}

void generate_numbers_from_stdin() {
    int num[2][2];
    printf("Enter 4 numbers:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &num[i][j]);
        }
    }
    display_numbers(num);
}