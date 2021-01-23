#include "core.h"

struct Employee {
  int id;
  char name[];
};

int main(void) {
  struct Employee *employee = malloc(sizeof(*employee) + sizeof(char) * 128);

  employee->id = 1;
  strcpy(employee->name, "Rayyh");

  assert(employee->id == 1);
  assert(strcmp(employee->name, "Rayyh") == 0);

  return 0;
}
