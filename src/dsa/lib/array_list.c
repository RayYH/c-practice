#include "array_list.h"

void InitList(ArrayList *array_list) {
  array_list->length = 0;
}

void DisplayList(ArrayList *array_list) {
  for (int i = 0; i < array_list->length; i++) {
    printf("%4d", array_list->data[i]);
  }
  NEW_LINE
}

bool InsertElement(ArrayList *array_list, int i, ElemType e) {
  // validate i
  if (i < 1 || i > array_list->length + 1) {
    return false;
  }

  // validate length
  if (array_list->length >= ARRAY_LIST_MAX_SIZE) {
    return false;
  }

  int current_index = array_list->length - 1;
  while (current_index >= i - 1) {
    array_list->data[current_index + 1] = array_list->data[current_index];
    current_index--;
  }
  array_list->data[i - 1] = e;
  array_list->length++;

  return true;
}

bool DeleteElement(ArrayList *array_list, int i, ElemType *e) {
  if (i < 1 || i > array_list->length) {
    return false;
  }

  *e = array_list->data[i - 1];

  int current_index = i - 1;
  while (current_index < array_list->length - 1) {
    array_list->data[current_index] = array_list->data[current_index + 1];
    current_index++;
  }
  array_list->length--;
}

void ReverseList(ArrayList *array_list) {
  ElemType temp;
  int mid = array_list->length / 2;
  for (int i = 0; i < mid; i++) {
    temp = array_list->data[i];
    array_list->data[i] = array_list->data[array_list->length - 1 - i];
    array_list->data[array_list->length - 1 - i] = temp;
  }
}
