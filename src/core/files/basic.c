#include "core.h"
#include "files.h"

int main(void) {
  int num = 123;
  FILE *fptr;

  fptr = fopen(tmp_file, "w");

  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  fprintf(fptr, "%d", num);
  fclose(fptr);

  if ((fptr = fopen(tmp_file, "r")) == NULL) {
    printf("Error occurred when opening a file.");
    exit(1);
  }

  fscanf(fptr, "%d", &num);
  printf("Value of n = %d", num);

  fclose(fptr);

  return 0;
}
