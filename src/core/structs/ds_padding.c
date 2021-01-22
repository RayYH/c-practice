#include "core.h"

// structures will be padded to 4-byte alignment
typedef struct {
  char Data1; // 1
  // 3-Bytes Added here.
  int Data2; // 4
  unsigned short Data3; // 2
  char Data4; // 1
  //1-byte Added here.

} sSampleStruct;

typedef struct {
  char Data1;
  int Data2;
  unsigned short Data3;
  char Data4;

}__attribute__((packed, aligned(1))) sSampleStruct2;

typedef struct {
  int an_int;
  char buf[]; // flexible array
} int_s;

int main(void) {
  assert(sizeof(sSampleStruct) == 12);
  assert(sizeof(sSampleStruct2) == 8);
  assert(sizeof(int_s) == 4);

  return 0;
}
