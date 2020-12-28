// http://cslibrary.stanford.edu/110/BinaryTrees.html
#include "tree.h"

struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

/*
 Given a binary tree, return true if a item
 with the target data is found in the tree. Recurs
 down the tree, chooses the left or right
 branch by comparing the target to each item.
*/
static bool lookup(struct node *item, int target) {
  if (item == NULL) {
    return false;
  } else {
    if (target == item->data) {
      return true;
    } else {
      if (target < item->data) return (lookup(item->left, target));
      else return (lookup(item->right, target));
    }
  }
}
