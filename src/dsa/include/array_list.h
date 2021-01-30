#ifndef C_PRACTICE_SRC_DSA_INCLUDE_LIST_H_
#define C_PRACTICE_SRC_DSA_INCLUDE_LIST_H_

#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

#define NEW_LINE printf("\n");

#define ARRAY_LIST_MAX_SIZE 50
#define ElemType int

typedef struct {
  ElemType data[ARRAY_LIST_MAX_SIZE];
  int length;
} ArrayList;

void InitList(ArrayList *array_list);

void DisplayList(ArrayList *array_list);

bool InsertElement(ArrayList *array_list, int i, ElemType e);

bool DeleteElement(ArrayList *array_list, int i, ElemType *e);

void ReverseList(ArrayList *array_list);

#endif //C_PRACTICE_SRC_DSA_INCLUDE_LIST_H_
