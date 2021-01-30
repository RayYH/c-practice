#include "array_list.h"
#include "assert.h"

int main(void) {
  ArrayList array_list;
  InitList(&array_list);

  assert(array_list.length == 0);
  InsertElement(&array_list, 1, 10);
  InsertElement(&array_list, 1, 20);
  InsertElement(&array_list, 1, 30);
  InsertElement(&array_list, 1, 40);
  InsertElement(&array_list, 1, 50);
  DisplayList(&array_list);

  ReverseList(&array_list);
  DisplayList(&array_list);

  ElemType e;
  DeleteElement(&array_list, 1, &e);
  DisplayList(&array_list);
  DeleteElement(&array_list, 2, &e);
  DisplayList(&array_list);
  DeleteElement(&array_list, 3, &e);
  DisplayList(&array_list);

  return 0;
}
