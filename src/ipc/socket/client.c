#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(void) {
  int sock;
  int read_size;
  struct sockaddr_in server;
  char message[1000], server_reply[2000];
  char *prompt = "[-] server  reply: \0";
  memset(message, '0', sizeof(message));

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Could not create socket");
  }
  puts("[x] socket created");

  memset(&server, '0', sizeof(server));
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);

  // 连接到服务端
  if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
    perror("connect failed. Error");
    return 1;
  }

  puts("[x] connected\n");

  // 与服务端持续通信
  while (1) {
    printf("[-] enter message: ");
    if (fgets(message, sizeof(message), stdin) != NULL) {
      // 发送数据
      if (send(sock, message, strlen(message), 0) < 0) {
        close(sock);
        puts("Send failed");
        return 1;
      }
    }
    write(STDOUT_FILENO, prompt, strlen(prompt));
    if ((read_size = recv(sock, server_reply, 2000, 0)) > 0) {
      server_reply[read_size] = '\0';
      write(STDOUT_FILENO, server_reply, read_size + 1);
      memset(server_reply, ' ', sizeof(server_reply));
    }
  }
}
