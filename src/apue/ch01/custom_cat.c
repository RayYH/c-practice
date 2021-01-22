#include "apue.h"

#define BUFF_SIZE 4096

/**
 * The program copies lines that we type to the standard output until we
 * type the end-of-file character (usually Control-D).
 *
 * ./custom_cat > data
 * Press Ctrl+D will terminate the program.
 *
 * ./custom_cat < infile > outfile
 * The file named infile will be copied to the file named outfile.
 *
 * @return void
 */
int main(void) {
  int n;
  char buf[BUFF_SIZE];

  // The constants STDIN_FILENO and STDOUT_FILENO are defined in <unistd.h>
  // and specify the file descriptors for standard input and standard output.
  while ((n = read(STDIN_FILENO, buf, BUFF_SIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      err_sys("write error");
    }
  }

  if (n < 0) {
    err_sys("read error");
  }

  exit(0);
}
