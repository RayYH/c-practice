#include "core.h"

int main(void) {
  char carr[] = "hello";
  char *p = carr;

  // value++
  assert(++*p);
  assert((*p) == 'i');
  // pointer++
  assert(*p++);
  assert((*p) == 'e');

  int arr1[] = {10, 20};
  int arr2[] = {10, 20};
  int arr3[] = {10, 20};
  int *p1 = arr1;
  int *p2 = arr2;
  int *p3 = arr3;


  // value++
  ++*p1;
  assert(arr1[0] == 11);
  assert(arr1[1] == 20);
  assert(*p1 == 11);

  // pointer++
  p2++;
  assert(arr2[0] == 10);
  assert(arr2[1] == 20);
  assert(*p2 == 20);

  // pointer++, * symbol is useless, here can be used to retrieve the value
  assert(*p3++);
  assert(arr3[0] == 10);
  assert(arr3[1] == 20);
  assert(*p3 == 20);
}
