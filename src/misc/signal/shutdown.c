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

// 使用 sigaction 为信号注册回调，为了简单，本例中我们使用了 signal 函数 (child_code 代码块)
void set_handler() {
  struct sigaction current;
  // 将 current 的信号集先清空
  sigemptyset(&current.sa_mask);
  // 设置为 0 代表不设置任何模式
  current.sa_flags = 0;
  // 设置处理函数
  current.sa_handler = graceful;
  // 绑定回调
  sigaction(SIGTERM, &current, NULL);
}

void child_code() {
  signal(SIGTERM, graceful);

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

int main(void) {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    return -1;
  }
  if (0 == pid) {
    child_code();
  } else {
    parent_code(pid);
  }
  return 0;
}
