#include "stdio.h"
#include "time.h"
#include "stdlib.h"

#define ELEM_MAX 100
#define ELEM_MIN 1
#define HL "____________________________________________________"
#define START printf("\n");printf(__FUNCTION__);printf(":\n%s\n", HL);
#define END printf("\n");

/**
 * One-dimensional array traversal.
 */
void traversal_one_dimensional_array() {
    START
    int nums[5] = {12, 28, 3, 1, 9};

    for (int i = 0; i < (sizeof(nums) / sizeof(int)); i++) {
        printf("nums[%d] is equal to %d\n", i, nums[i]);
    }
    END
}

/**
 * Two-dimensional array traversal.
 */
void traversal_two_dimensional_array() {
    START
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
    END
}

/**
 * Get input from stdin and save it to an array.
 */
void array_from_stdin() {
    START
    int values[5];

    printf("\nEnter 5 integers: ");
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
 * A common two-dimensional array traversal method. If there's an array `arr[i][j]`, the accepted params are:
 *
 * `&arr[0][0]` or `(int *) arr`, `i`, `j`.
 *
 * @param arr the first element's location
 * @param outer_size outer size
 * @param inner_size inner size
 */
void display_two_dimensional_array(int *arr, int outer_size, int inner_size) {
    for (int i = 0; i < outer_size; i++) {
        for (int j = 0; j < inner_size; j++) {
            printf("%-4d", *(arr + (i * inner_size) + j));
        }

        printf("\n");
    }

    printf("\n");
}

/**
 * Matrix addition.
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
    END
}

/**
 * Calculate the sum of given array.
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
 * We can pass whole array as a parameter to a function.
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
    traversal_one_dimensional_array();
    traversal_two_dimensional_array();
    sum_square_matrix();
    not_certain_size_array();
    array_from_stdin();

    return 0;
}