#include "std.h"
#include "stdlib.h"

int main(void) {
  printf("EXIT_FAILURE(Failure termination code) = %d\n", EXIT_FAILURE);
  printf("EXIT_SUCCESS(Success termination code) = %d\n", EXIT_SUCCESS);
  printf("MB_CUR_MAX(Maximum size of multibyte characters) = %d\n", MB_CUR_MAX);
  printf("RAND_MAX(Maximum value returned by rand) = %d\n", RAND_MAX);
  printf("NULL(Null pointer) = %p\n", NULL);

  return 0;
}
