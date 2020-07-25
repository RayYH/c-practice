#include "stdio.h"
#include "stdlib.h"

static char tmp_file[100] = "/tmp/c-practice-core-files.txt";

/**
 * r: Open for reading.
 * If the file does not exist, fopen() returns NULL.
 *
 * rb: Open for reading in binary mode.
 * If the file does not exist, fopen() returns NULL.
 *
 * w: Open for writing.
 * If the file does not exist, it will be created.
 *
 * wb: Open for writing in binary mode.
 * If the file exists, its contents are overwritten.
 *
 * a:  Open for append. Data is added to the end of the file.
 * If the file does not exist, it will be created.
 *
 * ab: Open for append in binary mode. Data is added to the end of the file.
 * If the file does not exist, it will be created.
 *
 * r+: Open for both reading and writing.
 * If the file does not exist, fopen() returns NULL.
 *
 * rb+: Open for both reading and writing in binary mode.
 * If the file does not exist, fopen() returns NULL.
 *
 * w+: Open for both reading and writing.
 * If the file exists, its contents are overwritten. If the file does not
 * exist, it will be created.
 *
 * wb+: Open for both reading and writing in binary mode.
 * If the file exists, its contents are overwritten. If the file does not
 * exist, it will be created.
 *
 * a+: Open for both reading and appending.
 * If the file does not exist, it will be created.
 *
 * ab+: Open for both reading and appending in binary mode.
 * If the file does not exist, it will be created.
 */

void file_usage() {
  int num = 123;
  FILE *fptr;

  fptr = fopen(tmp_file, "w");

  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  fprintf(fptr, "%d", num);
  fclose(fptr);

  // read file
  if ((fptr = fopen(tmp_file, "r")) == NULL) {
    printf("Error occurred when opening a file.");
    exit(1);
  }
  fscanf(fptr, "%d", &num);
  printf("Value of n = %d", num);
  fclose(fptr);
}

int main(void) {
  file_usage();

  return 0;
}