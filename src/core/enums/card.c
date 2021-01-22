#include "core.h"

enum suit {
  club = 0,
  diamonds = 10,
  hearts = 20,
  spades = 3
} card; // You can also use an alias, card can hold any value in this enum

int main(void) {
  card = club;
  assert(sizeof(card) == sizeof(int));
  assert(club == 0);
  assert(diamonds == 10);
  assert(hearts == 20);
  assert(spades == 3);

  enum suit var;
  var = diamonds;
  assert(var == diamonds);

  return 0;
}
