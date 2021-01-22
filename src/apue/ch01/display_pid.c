#include "apue.h"

int main(void) {
  // A program is read into memory and is executed by the kernel as a result
  // of one of the seven exec functions.

  // An executing instance of a program is called a process.

  // The UNIX System guarantees that every process has a unique numeric
  // identifier called the process ID. The process ID is always a
  // non-negative integer.

  // getpid returns a pid_t data type.
  // We don’t know its size; all we know is that the standards guarantee that
  // it will fit in a long integer.

  // There are three primary functions for process control:
  // fork, exec, and waitpid.
  printf("current pid = %ld\n", (long) getpid());

  exit(0);
}