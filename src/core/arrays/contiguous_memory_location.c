#include "core.h"
#include "time.h"

#define ARR_MAX_LENGTH 1000
#define LOOP_COUNT 100

void iteration_one(int *arr) {
  for (int i = 0; i < ARR_MAX_LENGTH; i++) {
    for (int j = 0; j < ARR_MAX_LENGTH; j++) {
      *(arr + (i * ARR_MAX_LENGTH) + j) = 0;
    }
  }
}

void iteration_two(int *arr) {
  for (int i = 0; i < ARR_MAX_LENGTH; i++) {
    for (int j = 0; j < ARR_MAX_LENGTH; j++) {
      *(arr + (j * ARR_MAX_LENGTH) + i) = 1;
    }
  }
}

double test(bool one, int *arr) {
  clock_t start = clock();

  if (one) {
    for (int i = 0; i < LOOP_COUNT; i++) {
      iteration_one(arr);
    }
  } else {
    for (int i = 0; i < LOOP_COUNT; i++) {
      iteration_two(arr);
    }
  }

  clock_t end = clock();
  double elapsed_time = (end - start) / (double) CLOCKS_PER_SEC;

  return elapsed_time;
}

int main(void) {
  int arr[5];
  for (int i = 0; i < 4; i++) {
    assert(((long) &arr[i + 1] - (long) &arr[i]) == sizeof(int));
  }

  int big_arr[ARR_MAX_LENGTH][ARR_MAX_LENGTH];
  double t1 = test(true, &big_arr[0][0]);
  double t2 = test(false, &big_arr[0][0]);
  // one: 0.22883000, two: 0.73459900
  printf("one: %.8f, two: %.8f", t1, t2);
}
