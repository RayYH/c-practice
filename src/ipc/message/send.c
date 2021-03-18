#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 100
#define TMP_FILE_PATH "/tmp/msg"

struct msg_buffer {
  long msg_type;
  char msg_text[100];
} message;

int main() {
  key_t key;
  int msg_id;

  // key_t ftok(const char *path, int id);
  // ftok 第一个参数是文件路径，一般的实现是组合给定文件的 inode 号和 id 生成一个 key
  key = ftok(TMP_FILE_PATH, 65);
  // int msgget(key_t key, int msgflg);
  // 返回 System V 消息队列的标识符
  msg_id = msgget(key, 0666 | IPC_CREAT);
  message.msg_type = 1;

  while (1) {
    printf("[-] write data: ");
    fgets(message.msg_text, MAX, stdin);
    msgsnd(msg_id, &message, sizeof(message), 0);
  }

  return 0;
}
