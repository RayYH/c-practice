#include "std.h"

int main(void) {
  printf("EXIT_FAILURE(Failure termination code) = %d\n", EXIT_FAILURE);
  printf("EXIT_SUCCESS(Success termination code) = %d\n", EXIT_SUCCESS);
#ifdef __linux__
  printf("MB_CUR_MAX(Maximum size of multibyte characters) = %ld\n",MB_CUR_MAX);
#endif
#ifdef __APPLE__
  printf("MB_CUR_MAX(Maximum size of multibyte characters) = %d\n", MB_CUR_MAX);
#endif
  printf("RAND_MAX(Maximum value returned by rand) = %d\n", RAND_MAX);
  printf("NULL(Null pointer) = %p\n", NULL);

  return 0;
}
