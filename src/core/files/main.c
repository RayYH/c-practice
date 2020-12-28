#include "core.h"

static char tmp_file[100] = "/tmp/c-practice-core-files.txt";

/**
 * Basic usage of file functions.
 */
void basic_usage() {
  START

  int num = 123;
  FILE *fptr;

  // open file
  fptr = fopen(tmp_file, "w");

  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  // write a formatted string
  fprintf(fptr, "%d", num);
  // close handle (file pointer)
  fclose(fptr);

  // open file again
  if ((fptr = fopen(tmp_file, "r")) == NULL) {
    printf("Error occurred when opening a file.");
    exit(1);
  }

  // read file contents
  fscanf(fptr, "%d", &num);
  printf("Value of n = %d", num);
  fclose(fptr);

  END
}

/**
 * Difference between fseek and rewind.
 *
 * In C, fseek() should be preferred over rewind().
 * The rewind function sets the file position indicator for the stream pointed
 * to by stream to the beginning of the file. It is equivalent to
 * (void)fseek(stream, 0L, SEEK_SET)
 * except that the error indicator for the stream is also cleared.
 */
void fseek_vs_rewind() {
  FILE *fp = fopen(tmp_file, "r");

  if (fp != NULL) {
    rewind(fp);
    // or
    if (fseek(fp, 0L, SEEK_SET) != 0) {
      // Do something else
    }
  }
}

/**
 * getc function.
 *
 * Comparing the value returned by getc() with EOF is not sufficient to check
 * for actual end of file. C provides feof() which returns non-zero value only
 * if end of file has reached, otherwise it returns 0.
 */
void getc_returns_eof_vs_feof() {
  START

  FILE *fp = fopen(tmp_file, "r");
  int ch = getc(fp);

  while (ch != EOF) {
    /* display contents of file on screen */
    putchar(ch);
    ch = getc(fp);
  }

  if (feof(fp)) {
    printf("\nEnd of file reached.");
  } else {
    printf("\nSomething went wrong.");
  }

  fclose(fp);

  END
}

/**
 * w vs wx mode.
 *
 * w mode: If a file with the same name already exists, its contents are
 * discarded and the file is treated as a new empty file.
 * wx mode: x is exclusive create-and-open mode. When x is used with w,
 * fopen() returns NULL if file already exists or could not open.
 */
void w_vs_wx_mode() {
  START

  FILE *fp = fopen(tmp_file, "w");
  if (fp == NULL) {
    puts("Couldn't open file");
    exit(0);
  } else {
    fputs("Hello World", fp);
    puts("Done");
    fclose(fp);
  }

  fp = fopen(tmp_file, "wx");
  if (fp == NULL) {
    puts("Couldn't open file");
    exit(0);
  } else {
    fputs("Hello World", fp);
    puts("Done");
    fclose(fp);
  }

  END
}

int main(void) {
  basic_usage();
  fseek_vs_rewind();
  getc_returns_eof_vs_feof();
  w_vs_wx_mode();

  return 0;
}
