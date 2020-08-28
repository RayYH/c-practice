#include "apue.h"

/**
 * This program copies standard input to standard output and can copy any
 * regular file.
 *
 * @return
 */
int main(void) {
  int c;
  // The standard I/O constants stdin and stdout are also defined in the
  // <stdio.h> header and refer to the standard input and standard output.

  // stdin/stdout - FILE* (stream)
  // STDIN_FILENO/STDOUT_FILENO - int (fd)

  // getc: http://www.cplusplus.com/reference/cstdio/getc/
  while ((c = getc(stdin)) != EOF) {
    // putc: http://www.cplusplus.com/reference/cstdio/putc/
    if (putc(c, stdout) == EOF) {
      err_sys("output error");
    }
  }

  if (ferror(stdin)) {
    err_sys("input error");
  }

  exit(0);
}