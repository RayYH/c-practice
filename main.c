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

    printf("Before:\n");
    display(arr);
    bubble_sort(arr, ARRAY_NUM);

    printf("\n\nAfter:\n");
    display(arr);

    return 0;
}
