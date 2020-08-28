#include "stdio.h"
#include "assert.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "core.h"

// https://www.programiz.com/c-programming/c-operators
// https://www.geeksforgeeks.org/c-programming-language/

// string-ing operator #
#define make_str(s) #s
// token-pasting operator
#define concat(a, b) a##b
// define (one two three);
#define parenthesis (one, two, three);
#define no_parenthesis one, two, three;

/**
 * Arithmetic operators.
 */
void arithmetic_operators() {
  START

  int a = 9, b = 4, c;
  c = a + b;
  printf("a+b = %d \n", c);
  c = a - b;
  printf("a-b = %d \n", c);
  c = a * b;
  printf("a*b = %d \n", c);
  c = a / b;
  printf("a/b = %d \n", c);
  c = a % b;
  printf("Remainder when a divided by b = %d \n", c);

  END
}

/**
 * Increment and decrement operators.
 */
void increment_decrement_operators() {
  START

  int a = 10, b = 100;
  float c = 10.5f, d = 100.5f;

  ++a;
  --b;
  ++c;
  --d;
  printf("++a = %d \n", a);
  printf("--b = %d \n", b);
  printf("++c = %f \n", c);
  printf("--d = %f \n", d);

  END
}

/**
 * Assignment operators.
 */
void assignment_operators() {
  START

  int a = 5, c;

  c = a;      // c is 5
  printf("c = %d\n", c);
  c += a;     // c is 10
  printf("c = %d\n", c);
  c -= a;     // c is 5
  printf("c = %d\n", c);
  c *= a;     // c is 25
  printf("c = %d\n", c);
  c /= a;     // c is 5
  printf("c = %d\n", c);
  c %= a;     // c = 0
  printf("c = %d\n", c);

  END
}

/**
 * Relational operators.
 */
void relational_operators() {
  START

  int a = 5, b = 5, c = 10;

  printf("%d == %d is %d \n", a, b, a == b);
  printf("%d == %d is %d \n", a, c, a == c);
  printf("%d > %d is %d \n", a, b, a > b);
  printf("%d > %d is %d \n", a, c, a > c);
  printf("%d < %d is %d \n", a, b, a < b);
  printf("%d < %d is %d \n", a, c, a < c);
  printf("%d != %d is %d \n", a, b, a != b);
  printf("%d != %d is %d \n", a, c, a != c);
  printf("%d >= %d is %d \n", a, b, a >= b);
  printf("%d >= %d is %d \n", a, c, a >= c);
  printf("%d <= %d is %d \n", a, b, a <= b);
  printf("%d <= %d is %d \n", a, c, a <= c);

  END
}

/**
 * Logical operators.
 */
void logical_operators() {
  START

  int c = 10, result;
  int a = c / 2;
  int b = c / 2;

  result = (a == b) && (c > b);
  printf("(a == b) && (c > b) is %d \n", result);
  result = (a == b) && (c < b);
  printf("(a == b) && (c < b) is %d \n", result);
  result = (a == b) || (c < b);
  printf("(a == b) || (c < b) is %d \n", result);
  result = (a != b) || (c < b);
  printf("(a != b) || (c < b) is %d \n", result);
  printf("!((a != b) || (c < b)) is %d \n", !result);

  int x = 10, y = 10;
  // in c++, sizeof(x == y) is 1
  assert(sizeof(x == y) == sizeof(int));

  END
}

/**
 * Bitwise operators.
 */
void bitwise_operators() {
  START

  /**
   * 12 = 00001100 (In Binary)
   * 25 = 00011001 (In Binary)
   *
   * Bit Operation of 12 and 25
   *   00001100
   * & 00011001
   *   ________
   *   00001000  = 8 (In decimal)
   */

  unsigned int a = 12, b = 25;
  printf("12 & 25 = %d\n", a & b);

  /**
   * 12 = 00001100 (In Binary)
   * 25 = 00011001 (In Binary)
   *
   * Bitwise OR Operation of 12 and 25
   *   00001100
   * | 00011001
   *   ________
   *   00011101  = 29 (In decimal)
   */
  printf("12 | 25 = %d\n", a | b);

  /**
   * 12 = 00001100 (In Binary)
   * 25 = 00011001 (In Binary)
   *
   * Bitwise XOR Operation of 12 and 25
   *   00001100
   * ^ 00011001
   *   ________
   *   00010101  = 21 (In decimal)
   */
  printf("12 ^ 25 = %d\n", a ^ b);

  /**
   * Two's complement is an operation on binary numbers.
   * The 2's complement of a number is equal to
   * the complement of that number plus 1.
   *
   * Decimal      Binary           2's complement
   *   0          00000000         -(11111111+1) = -00000000 = -0(decimal)
   *   1          00000001         -(11111110+1) = -11111111 = -256(decimal)
   *   12         00001100         -(11110011+1) = -11110100 = -244(decimal)
   *   220        11011100         -(00100011+1) = -00100100 = -36(decimal)
   *
   * Note: Overflow is ignored while computing 2's complement.
   *
   * bitwise complement of N = ~N (represented in 2's complement form)
   * 2'complement of ~N= -(~(~N)+1) = -(N+1)
   */

  printf("~12 = %d\n", ~a);
  printf("~-25 = %d\n", ~-b);

  /**
   * Right Shift Operator
   *
   * 212 = 11010100 (In binary)
   * 212>>2 = 00110101 (In binary) [Right shift by two bits]
   * 212>>7 = 00000001 (In binary)
   * 212>>8 = 00000000
   * 212>>0 = 11010100 (No Shift)
   *
   * Left Shift Operator
   * 212 = 11010100 (In binary)
   * 212<<1 = 110101000 (In binary) [Left shift by one bit]
   * 212<<0 =11010100 (Shift by 0)
   * 212<<4 = 110101000000 (In binary) =3392(In decimal)
   */

  unsigned int num = 212, i;
  for (i = 0; i <= 2; ++i) {
    printf("212 right shift by %d: %d\n", i, num >> i);
  }

  for (i = 0; i <= 2; ++i) {
    printf("212 left shift by %d: %d\n", i, num << i);
  }

  END
}

/**
 * Short circuiting in logical operators.
 */
void short_circuiting_in_logical_operators() {
  START

  int a = 4;
  int b = 10;
  a > b || printf("a < b!\n");
  b > a && printf("b > a!\n");

  printf("\n");
}

/**
 * Function to return the only odd occurring element.
 *
 * @param arr given array
 * @param n the array length
 * @return the only odd occurring element
 */
int find_odd(int arr[], int n) {
  int res = 0, i;

  for (i = 0; i < n; i++) {
    res ^= arr[i];
  }

  return res;
}

/**
 * find_odd test function.
 */
void find_odd_test() {
  int arr[] = {12, 12, 14, 90, 14, 14, 14};
  int n = sizeof(arr) / sizeof(arr[0]);
  assert(find_odd(arr, n) == 90);
}

/**
 * Function to check if given value is an even number.
 *
 * @param x given value
 * @return true if x is even, otherwise false
 */
bool is_even(int x) {
  return (x & 1) ? true : false;
}

/**
 * test is_even function.
 */
void is_even_test() {
  assert(is_even(1));
  assert(!is_even(2));
}

// global variable
int x = 0;

/**
 * change x to 5.
 *
 * @return x
 */
int f1() {
  x = 5;
  return x;
}

/**
 * change x to 10.
 *
 * @return x
 */
int f2() {
  x = 10;
  return x;
}

/**
 * test x value.
 */
void x_test() {
  START

  int p = f1() + f2();
  printf("p = %d\n", p);
  printf("x = %d\n", x);

  END
}

/**
 * Comma operator.
 */
void comma_operator() {
  START

  assert(10 == (f1(), f2()));

  int z = 10;
  // not 11 but 12
  // calculate all statements then return right variable's value
  int y = (z++, ++z);
  assert(y == 12); // equals to ++z
  assert(z == 12);
  z = 10;
  int y2 = (z++, z++);
  assert(y2 == 11); // equals to z++
  assert(z == 12);

  int p = 10, q;
  // The following is equivalent to
  // q = p + 2 and p += 3,
  // with two printings
  // the exec order is from left to right
  q = (p++, printf("p = %d\n", p), ++p, printf("p = %d\n", p), p++);
  // q --> p++ (so q must be equal to p-1)
  assert(p == 13);
  assert(q == 12);

  int one = 1, two = 2, three = 3;
  int a;
  a = no_parenthesis
  assert(a == one);
  a = parenthesis
  assert(a == three);

  END
}

/**
 * Chaining of comparison operators.
 */
void chaining_of_comparison_operators() {
  int a = 1, b = 20, c = 30;

  // (c > b <= a) is treated as ((c  > b) <= a)
  // Therefore the value becomes ((30 > 20) <= 10)
  // which becomes (0 <= 20)
  assert(c > b <= a);
}

/**
 * Sizeof.
 */
void sizeof_operator() {
  START

  // get size
  int a = 0;
  double d = 10.21;
  assert(8 == sizeof(a + d));

  // counting number of array elements
  int arr[] = {1, 2, 3, 4, 7, 98, 0, 12, 35, 99, 14};
  assert(11 == sizeof(arr) / sizeof(arr[0]));

  // allocate a block of memory dynamically
  int *ptr = (int *) malloc(10 * sizeof(int));
  free(ptr);

  // The printf in sizeof is not executed
  // Only the return type of printf is
  // considered and its size is evaluated
  // by sizeof,
  int s = sizeof(printf("hey"));
  assert(s == 4); // printf returns value of int type

  // compare to strlen - every string terminates with a NULL character (“\0”).
  char str[] = "November";
  assert(strlen(str) == 8);
  assert(sizeof(str) == 9);

  char arr1[] = {"Geeks for"};
  char arr2[] = {'G', 'e', 'e', 'k', 's', ' ', 'f', 'o', 'r'};
  char arr3[] = {'G', 'e', 'e', 'k', 's', ' ', 'f', 'o', 'r', '\0'};
  assert(sizeof(arr1) == 10);
  assert(strlen(arr1) == 9);
  assert(sizeof(arr2) == 9);
  assert(strlen(arr2) >= 9 * sizeof(char));
  printf(" %c ", *(arr2 + 9));
  *(arr2 + 9) = '\0';
  assert(strlen(arr2) == 9 * sizeof(char));
  assert(strlen(arr3) == 9 * sizeof(char));

  END
}

/**
 * Simple function returns zero.
 *
 * @return constant 0
 */
int zero() {
  return 0;
}

/**
 * Test ternary operator.
 */
void ternary_operator() {
  int i = zero();
  assert((i ? 3 : 'A') == 65);
  assert((i ? 3 : 'A') == 'A');
}

/**
 * Test macros.
 */
void macro_test() {
  START

  printf(make_str(helloworld));
  printf("\n");
  int xy = 30;
  printf("%d", concat(x, y));

  END
}

int main(void) {
  arithmetic_operators();
  increment_decrement_operators();
  assignment_operators();
  logical_operators();
  relational_operators();
  bitwise_operators();
  short_circuiting_in_logical_operators();
  find_odd_test();
  x_test();
  chaining_of_comparison_operators();
  comma_operator();
  sizeof_operator();
  ternary_operator();
  is_even_test();
  macro_test();

  return 0;
}