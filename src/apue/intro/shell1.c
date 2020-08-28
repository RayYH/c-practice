#include "apue.h"
#include "sys/wait.h"

int main(void) {

  // from apue.h
  char buf[MAXLINE];
  pid_t pid;
  int status;

  // print prompt $
  printf("$ ");
  // Use fgets to read one line at a time from the standard input.

  // When we type the end-of-file character (which is often Control-D) as the
  // first character of a line, fgets returns a null pointer, the loop stops,
  // and the process terminates.

  // getc: http://www.cplusplus.com/reference/cstdio/fgets/
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    // replace the newline with a null byte
    // because the execlp function wants a null-terminated argument
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }
    // We call fork to create a new process, which is a copy of the caller.

    // We say that the caller is the parent and that the newly created
    // process is the child.

    // fork returns the non-negative process ID of the new child process to
    // the parent, and returns 0 to the child.

    // Because fork creates a new process, we say that it is
    // called once—by the parent
    // but returns twice—in the parent and in the child.

    // https://www.man7.org/linux/man-pages/man2/fork.2.html
    if ((pid = fork()) < 0) { // On failure, -1 is returned in the parent
      err_sys("fork error");
    } else if (pid == 0) {
      // pid = 0, means in child precess
      // int execlp(const char *file, const char *arg, ...);
      // execute the command that was read from the standard input.
      execlp(buf, buf, (char *) 0);
      err_ret("couldn't execute: %s", buf);
      exit(127);
    }

    // The combination of fork followed by exec is called spawning a new
    // process on some operating systems.

    // Below statements executed inside parent process scope

    // waitpid specify which process to wait for: the pid argument, which is
    // the process ID of the child.
    // waitpid returns the termination status of the child.
    pid = waitpid(pid, &status, 0);
    if (pid < 0) {
      err_sys("waitpid error");
    }

    printf("\n$ ");
  }

  exit(0);
}