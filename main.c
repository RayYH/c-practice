#include <stdio.h>
#include "algorithms/sorting/helper.h"
#include "algorithms/sorting/sorting.h"

void data_types() {
    int age = 24;
    double gpa = 3.9;
    char grade = 'A';
    // you
    char phrase[] = "Hello, C";
}

void c_basic() {
    // define a constant - PI can't be modified
    const double PI = 3.14;
    // integer
    int age = 24;
    // char array - strings
    char name[] = "Ray";
    // char
    char grade = 'A';
    // float
    float gpa = 3.9f;
    // double
    double height = 174.80;

    int favorite_number;

    printf("Hello, C-Practice!\n");
    printf("PI = %g\n", PI);
    printf("%s's age is %d\n", name, age);
    printf("%s's gpa is %f\n", name, gpa);
    printf("%s's height is %.1f\n", name, height);
    printf("%s's grade is %c", name, grade);

    printf("\n\n\n");
    printf("Enter your favorite integer: ");
    scanf("%d", &favorite_number);
}

int main() {

    int *arr = random_array();
    int *arr2 = copy(arr);
    int *arr3 = copy(arr);

    printf("Source Data:\n");
    display(arr);
    printf("Bubble Sort...\n\n");
    bubble_sort(arr, ARRAY_NUM);
    display(arr);
    printf("\ncompare num: %d\nswap num: %d", compare_num, swap_num);

    printf("\n");
    bubble_sort_with_flag(arr2, ARRAY_NUM);
    display(arr2);
    printf("\ncompare num: %d\nswap num: %d", compare_num, swap_num);

    printf("\n");
    bubble_sort_with_flag_and_boundary(arr3, ARRAY_NUM);
    display(arr3);
    printf("\ncompare num: %d\nswap num: %d", compare_num, swap_num);

    return 0;
}
