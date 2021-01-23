#include "core.h"
/**
 * @see https://stackoverflow.com/questions/11770451/what-is-the-meaning-of-attribute-packed-aligned4
 * @see https://stackoverflow.com/questions/4306186/structure-padding-and-packing
 *
 * When a modern computer reads from or writes to a memory address, it will do
 * this in word sized chunks (e.g. 4 byte chunks on a 32-bit system).
 *
 * Data alignment means putting the data at a memory offset equal to some
 * multiple of the word size, which increases the system's performance
 * due to the way the CPU handles memory.
 *
 * To align the data, it may be necessary to insert some meaningless bytes
 * between the end of the last data structure and the start of the next,
 * which is data structure padding.
 *
 * gcc provides functionality to disable structure padding. i.e to avoid
 * these meaningless bytes in some cases.
 *
 * We can use __attribute__((packed, aligned(X))) to insist particular(X)
 * sized padding. X should be powers of two.
 *
 * if Struct's largest member is long then divisible by 8, int then by 4,
 * short then by 2.
 */

// padded to 2-bytes alignment
typedef struct {
  char data_1;           // 1 Byte --> add 1 byte here
  unsigned short data_2; // 2 Bytes
} s1;

// padded to 4-bytes alignment
typedef struct {
  char data_1;           // 1 Byte --> add 3 bytes here
  int data_2;            // 4 Bytes
  unsigned short data_3; // 2 Bytes
  char data_4;           // 1 Byte --> add 1 byte here
} s2;

// padded to 8-bytes alignment
typedef struct {
  char data_1;   // 1 Byte --> aligned to 8 (added 7 bytes here)
  double data_3; // 8 Bytes
} s3;

// use __attribute__ ((__packed__)) to insist 1 sized padding
// NOTE: unaligned memory access is slower on architectures that allow it
typedef struct {
  char data_1;           // 1 Byte
  int data_2;            // 4 Bytes
  unsigned short data_3; // 2 Bytes
  char data_4;           // 1 Bytes
  char data_5;           // 1 Bytes
}__attribute__ ((__packed__)) s4;

// padding to 8-bytes
typedef struct {
  char data_1;           // 1 Byte
  int data_2;            // 4 Bytes
  unsigned short data_3; // 2 Bytes
  char data_4;           // 1 Bytes
  char data_5;           // 1 Bytes
}__attribute__((packed, aligned(8))) s5;

int main(void) {
  assert(sizeof(s1) == 4);
  assert(sizeof(s2) == 12);
  assert(sizeof(s3) == 16);
  assert(sizeof(s4) == 9);
  assert(sizeof(s5) == 16);

  return 0;
}
