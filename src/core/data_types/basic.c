#include "core.h"

int main(void) {
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
  printf("PI = %g\n", PI);
  printf("%s's age is %d\n", name, age);
  printf("%s's gpa is %f\n", name, gpa);
  printf("%s's height is %.1f\n", name, height);
  printf("%s's grade is %c\n", name, grade);

  return 0;
}
