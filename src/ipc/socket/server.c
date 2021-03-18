#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

#define PORT 8888

// 客户端连接一旦建立，后续通信我们使用新的套接字来处理
void *connection_handler(void *);

int main(void) {
  int socket_desc, client_sock, c, *new_sock;
  struct sockaddr_in server, client;
  // 创建套接字: int socket(int domain, int type, int protocol);
  // domain 的取值可以是 AF_UNIX (本机通信)，AF_INET (IPV4)，AF_INET6 (IPV6) ...
  // type 的取值可以是 SOCK_STREAM (TCP)，SOCK_DGRAM (UDP)，SOCK_RAW (原始套接字) ...
  // protocol 代表协议，这里 type 已经指明了协议的类型，因此直接使用 0
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    printf("Could not create socket");
  }
  puts("[x] socket created");

  /**
   * sockaddr_in 中的 addr 和 port 存储在不同的变量
   * sockaddr 中使用一个数组来表示 addr 和 port，常作为 bind、connect 等函数的参数类型
   * 一般先对 sockaddr_in 类型变量进行赋值，然后强制类型转换为 sockaddr 类型
   */

  server.sin_family = AF_INET;         // 指定 IP 地址版本为 IPV4
  server.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY 表示监听 0.0.0.0 地址
  server.sin_port = htons(PORT);       // 端口号

  // 绑定套接字: int bind(int socket, const struct sockaddr *address, socklen_t address_len);
  // 将 address 指向的 sockaddr 结构体中描述的一些属性与 socket 套接字绑定
  // 如果一个 TCP 客户端或者服务器未曾调用 bind 捆绑一个端口，当调用 connect 或 listen 时，内核就要为相应的套接字选择一个临时接口
  // 一般而言，服务端会显式 bind，而客户端不执行 bind 操作
  if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
    perror("[x] bind failed.");
    return 1;
  }
  puts("[x] bind done");

  // 监听套接字: int listen(int sockfd, int backlog);
  // backlog: backlog 队列的大小，即等待 accept 操作的连接大小
  listen(socket_desc, 20);

  puts("[x] waiting for incoming connections...");
  c = sizeof(struct sockaddr_in);

  // accept 提取出所监听套接字的等待连接队列中第一个连接请求，创建一个新的套接字，并返回指向该套接字的文件描述符。
  // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
  // sockfd - socket() 返回的套接字描述符
  // addr - 指向 sockaddr 的指针
  // addrlen - sizeof(struct sockaddr_in);
  // 如果队列中没有等待的连接，套接字也没有被标记为 Non-Blocking，accept() 会阻塞调用函数直到连接可用
  // 如果套接字被标记为 Non-Blocking，队列中也没有等待的连接，accept() 返回错误 EAGAIN 或 EWOULDBLOCK
  while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
    puts("[x] connection accepted");
    // 新建线程处理新到来的请求
    pthread_t sniffer_thread;
    new_sock = malloc(sizeof(int));
    *new_sock = client_sock;
    // int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
    // thread - 新创建的线程 ID 指向的内存单元
    // attr - 线程属性，默认为 NULL
    // start_routine - 新创建的线程从 start_routine 函数的地址开始运行
    // arg - 默认为 NULL，若上述函数需要参数，将参数放入结构中并将地址作为 arg 传入
    if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *) new_sock) != 0) {
      perror("could not create thread");
      return 1;
    }

    puts("[x] handler assigned");
  }

  if (client_sock < 0) {
    perror("accept failed");
    return 1;
  }

  return 0;
}

void *connection_handler(void *socket_desc) {
  int sock = *(int *) socket_desc;
  int read_size;
  char client_message[2000];

  // 接收客户端发送的消息
  while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
    // 将消息写回到客户端
    client_message[read_size] = '\0';
    write(sock, client_message, read_size + 1);
    memset(client_message, ' ', sizeof(client_message));
  }

  if (read_size == 0) {
    puts("[x] client disconnected");
    fflush(stdout);
  } else if (read_size == -1) {
    perror("recv failed");
  }

  // 释放套接字
  free(socket_desc);

  return 0;
}
