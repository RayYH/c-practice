#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg_buffer {
  long msg_type;
  char msg_text[100];
} message;

#define TMP_FILE_PATH "/tmp/msg"

int main() {
  key_t key;
  int msg_id;

  key = ftok(TMP_FILE_PATH, 65);
  msg_id = msgget(key, 0666 | IPC_CREAT);

  while (1) {
    msgrcv(msg_id, &message, sizeof(message), 1, 0);
    printf("[-] received data : %s", message.msg_text);
    sleep(1);
  }

  // 销毁消息队列 - 下面的代码不会执行，因为前面有一个无限循环
  msgctl(msg_id, IPC_RMID, NULL);
  return 0;
}
