#include "core.h"
#include "files.h"

/**
 * Comparing the value returned by getc() with EOF is not sufficient to check
 * for actual end of file. C provides feof() which returns non-zero value only
 * if end of file has reached, otherwise it returns 0.
 */
int main(void) {
  FILE *fp = fopen(tmp_file, "r");
  int ch = getc(fp);

  while (ch != EOF) {
    putchar(ch);
    ch = getc(fp);
  }

  if (feof(fp)) {
    printf("\nEnd of file reached.");
  } else {
    printf("\nSomething went wrong.");
  }

  fclose(fp);

  return 0;
}
