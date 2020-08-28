/*
 *******************************************************************************
 *
 * Useful Links:
 *
 * https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
 * https://www.geeksforgeeks.org/difference-between-definition-and-declaration/
 * https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
 * https://www.geeksforgeeks.org/static-variables-in-c/
 * https://www.geeksforgeeks.org/what-are-static-functions-in-c/
 * https://www.geeksforgeeks.org/variables-and-keywords-in-c/
 * https://www.geeksforgeeks.org/void-pointer-c-cpp/
 * https://www.geeksforgeeks.org/g-fact-16/
 *
 *******************************************************************************
 */

#include "assert.h"
#include <stdarg.h>
#include "core.h"

// global variable
int z = 10;
// type definition
typedef long long int LL;

/**
 * Variable Declaration.
 *
 * type variable_name;
 * type variable_1_name, variable_2_name, variable_3_name;
 */
void variables_assertion() {
  char b = 'G';
  LL c = 1000000;

  assert(b == 'G');
  assert(c == 1000000);

  int i = 0;
  while (i++ < 4) {
    // static variables will hold old values
    static int y = 5;
    y++;
    assert(y == 5 + i);
  }

  assert(z == 10);
}

/**
 * const keyword.
 *
 * const data_type var_name = var_value;
 *
 * Constant variables must be initialized during their declaration.
 * const keyword is also used with pointers.
 */
void const_keyword() {
  // i is a constant of int type
  const int i = 10;
  // i = 11 -> error
  assert(i == 10);

  int j = 20;
  // p is a pointer to int const (const int)
  const int *p = &j; // or you can use int const *p = &j;
  assert((*p) == 20);
  // we cannot change value by pointer(p of type const *): *p = 100;
  // but we can change p - (since p is not a constant)
  int k = 30;
  p = &k;
  assert((*p) == 30);

  // p_i is a pointer to const int
  int const *p_i = &i;
  assert((*p_i) == 10);
  /*
   * valid. We call it up qualification. In C/C++, the type of "int *" is
   * allowed to up qualify to the type "const int *". The type of &k is
   * "int *" and is implicitly up qualified by the compiler to "const int *"
   *
   * Down qualification is not allowed in C++ and may cause warnings in C.
   */
  p_i = &k; // also, we can change the value of pointer
  assert((*p_i) == 30);

  // p tr is a constant pointer to const int
  const int *const ptr = &i;
  assert((*ptr) == 10);
  // ptr = &j;    -> error
  // *ptr = 100;  -> error
}

/**
 * extern keyword.
 */
void extern_keyword() {
  // global_int was declared at the below
  extern int global_int;
  assert(global_int == 1);
  global_int = 10;
  assert(global_int == 10);
  global_int = 1;
  assert(global_int == 1);
}

/**
 * Void is considered a data type (for organizational purposes), but it is
 * basically a keyword to use as a placeholder where you would put a data
 * type, to represent "no data".
 */
void void_keyword() {
  // malloc() and calloc() return void * type and this allows these functions
  // to be used to allocate memory of any data type
  int a = 10;
  char b = 'b';

  void *p = &a;
  assert(*(int *) (p) == 10);

  p = &b;
  assert(*(char *) (p) == 'b');

  int c[2] = {1, 2};
  void *ptr = &c;
  ptr = ptr + sizeof(int);
  // Only in GNU C
  assert(*(int *) ptr == 2);
}

/**
 * Counter with static keyword.
 *
 * @return the count
 */
static int static_counter() {
  static int count;
  count++;

  return count;
}

/**
 * Counter without static keyword.
 *
 * @return the count
 */
static int counter() {
  int count = 0;
  count++;
  return count;
}

/**
 * Static variables are allocated memory in data segment, not stack segment.
 *
 * Static variables (like global variables) are initialized as 0 if not
 * initialized explicitly.
 *
 * In C, static variables can only be initialized using constant literals.
 * Static variables should not be declared inside structure.
 *
 * @return count
 */
void static_keyword() {
  assert(counter() == 1);
  assert(counter() == 1);
  assert(static_counter() == 1);
  assert(static_counter() == 2);
}

/**
 * To use rest parameters, you should include stdarg.h header file first.
 *
 * 1. Define a function with its last parameter as ellipses and the one just
 *    before the ellipses is always an int which will represent the number of
 *    arguments.
 * 2. Create a va_list type variable in the function definition.
 * 3. Use int parameter and va_start macro to initialize the va_list variable
 *    to an argument list.
 * 4. Use va_arg macro and va_list variable to access each item in argument
 *    list.
 * 5. Use a macro va_end to clean up the memory assigned to va_list variable.
 */
double average(int num, ...) {
  va_list variable_list;
  double sum = 0.0;
  int i;
  va_start(variable_list, num);

  for (i = 0; i < num; i++) {
    sum += va_arg(variable_list, int);
  }
  va_end(variable_list);

  return sum / num;
}

int main(void) {
  assert(global_int == 1);
  variables_assertion();
  const_keyword();
  extern_keyword();
  void_keyword();
  static_keyword();
  assert(average(4, 2, 3, 4, 5) == 3.5);
  assert(average(3, 5, 10, 15) == 10.0);

  return 0;
}