#ifndef C_PRACTICE_LINKED_LIST_H
#define C_PRACTICE_LINKED_LIST_H

#include "../common.h"

struct Node {
    int data;
    struct Node *next;
};

void print_list(struct Node *n);

#endif //C_PRACTICE_LINKED_LIST_H
