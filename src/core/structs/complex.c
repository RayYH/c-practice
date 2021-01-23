#include "core.h"
#include "math.h"

typedef struct Complex {
  float real;
  float imag;
} complex;

complex add(complex c1, complex c2);
float distance(complex c1, complex c2);

complex add(complex c1, complex c2) {
  complex result = {
      .real = c1.real + c2.real,
      .imag = c1.imag + c2.imag
  };
  return result;
}

float distance(complex c1, complex c2) {
  return sqrt(pow(c2.imag - c1.imag, 2) + pow(c2.real - c1.real, 2));
}

int main(void) {
  complex numbers[2] = {
      {.real = 1.0, .imag = 2.0},
      {.real = 4.0, .imag = 6.0}
  };
  complex result = add(numbers[0], numbers[1]);
  assert(result.real == 5.0);
  assert(result.imag == 8.0);
  assert(distance(numbers[0], numbers[1]) == 5.0);
}
