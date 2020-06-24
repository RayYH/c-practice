#include "linked_list.h"

// links:
// http://cslibrary.stanford.edu/103/LinkedListBasics.pdf
// https://www.geeksforgeeks.org/data-structures/linked-list/

/**
 * print linked list elements.
 */
void print_list(struct Node *n) {
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

/**
 * Given a reference (pointer to pointer) to the head of a list and an int,
 * inserts a new node on the front of the list.
 *
 * head_ref is a allocated memory location.
 *
 * If we use struct Node *head_ref, we can only get the first node's location,
 * which means we cannot get the location that head_ref refers to.
 */
void push(struct Node **head_ref, int new_data) {
    /* 1. allocate node */
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

