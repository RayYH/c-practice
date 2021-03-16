#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 250
#define READ_END 0
#define WRITE_END 1

int main(void) {
  char write_msg[BUFFER_SIZE] = "Greetings";
  char read_msg[BUFFER_SIZE];
  int fd[2];
  pid_t pid;

  // pipe 用于创建管道
  if (pipe(fd) == -1) {
    fprintf(stderr, "Pipe failed");
    return 1;
  }

  // fork 子进程
  pid = fork();

  if (pid < 0) { // fork 失败
    fprintf(stderr, "Fork Failed");
    return 1;
  }

  if (pid > 0) { // 父进程
    // 关闭不会使用的读取端
    close(fd[READ_END]);
    // 往写入端写三条消息
    write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
    sleep(1);
    write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
    sleep(1);
    write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
    // 关闭写入端
    sleep(1);
    close(fd[WRITE_END]);
  } else { // 子进程
    close(fd[WRITE_END]);
    read(fd[READ_END], read_msg, BUFFER_SIZE);
    printf("read %s\n", read_msg);
    read(fd[READ_END], read_msg, BUFFER_SIZE);
    printf("read %s\n", read_msg);
    read(fd[READ_END], read_msg, BUFFER_SIZE);
    printf("read %s\n", read_msg);
    close(fd[READ_END]);
  }

  return 0;
}
