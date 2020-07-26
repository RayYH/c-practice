#include "apue.h"

#define    BUFF_SIZE    4096

// ./custom_cat > data
// ./custom_cat < infile > outfile
int main(void) {
  int n;
  char buf[BUFF_SIZE];

  while ((n = read(STDIN_FILENO, buf, BUFF_SIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      err_sys("write error");
    }
  }

  if (n < 0)
    err_sys("read error");

  exit(0);
}
