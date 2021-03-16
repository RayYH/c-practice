#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void graceful(int signum) {
  printf("\tChild confirming received signal: %i\n", signum);
  puts("\tChild about to terminate gracefully...");
  sleep(1);
  puts("\tChild terminating now...");
  exit(0);
}

// 为信号注册回调
void set_handler() {
  struct sigaction current;
  // 是将 current 的信号集先清空
  sigemptyset(&current.sa_mask);
  //
  current.sa_flags = 0;
  current.sa_handler = graceful;
  sigaction(SIGTERM, &current, NULL);
}

void child_code() {
  set_handler();

  while (1) {
    sleep(1);
    puts("\tChild just woke up, but going back to sleep.");
  }
}

void parent_code(pid_t cpid) {
  puts("Parent sleeping for a time...");
  sleep(5);

  // 向子进程发送 SIGTERM 信号
  if (-1 == kill(cpid, SIGTERM)) {
    perror("kill");
    exit(-1);
  }
  wait(NULL);
  puts("My child terminated, about to exit myself...");
}

int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    return -1; /* error */
  }
  if (0 == pid) {
    child_code();
  } else {
    parent_code(pid);
  }
  return 0;
}
