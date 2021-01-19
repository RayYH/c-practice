// https://stackoverflow.com/questions/25172425/create-zombie-process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
  pid_t pid;
  int status;

  if ((pid = fork()) < 0) { // Error
    perror("fork");
    exit(1);
  }

  if (pid == 0) { // Chile
    exit(0);
  }

  // Parent: Gives you time to observe the zombie using ps(1) ...
  // while true; do clear && ps aux ; sleep 1; done
  sleep(100);

  /* and after that, parent wait(2)s its child's exit status, and prints a relevant message.*/
  pid = wait(&status);
  if (WIFEXITED(status)) {
    fprintf(stderr, "\n\t[%d]\tProcess %d exited with status %d.\n",
            (int) getpid(), pid, WEXITSTATUS(status));
  }

  return 0;
}
