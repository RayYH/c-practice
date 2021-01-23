#include "core.h"
#include "files.h"

/**
 * w mode: If a file with the same name already exists, its contents are
 * discarded and the file is treated as a new empty file.
 * wx mode: x is exclusive create-and-open mode. When x is used with w,
 * fopen() returns NULL if file already exists or could not open.
 */
int main(void) {
  FILE *fp = fopen(tmp_file, "w");
  if (fp == NULL) {
    puts("Couldn't open file with w mode");
    exit(0);
  } else {
    fputs("Hello World", fp);
    puts("Done");
    fclose(fp);
  }

  fp = fopen(tmp_file, "wx");
  if (fp == NULL) {
    puts("Couldn't open file with wx mode");
    exit(0);
  } else {
    fputs("Hello World", fp);
    puts("Done");
    fclose(fp);
  }

  return 0;
}
