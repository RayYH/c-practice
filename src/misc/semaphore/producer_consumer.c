// 基于 https://github.com/codophobia/producer-consumer-problem-solution-in-c/blob/master/producer-consumer.c
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

// 是否开启调试模式，调试模式会打印信号量的值
#define DEBUG_MODE 1

#ifdef DEBUG_MODE
#include <errno.h>
#include <string.h>
int sem_v;
int op;
#endif

#define MAX_ITEMS 5   // 每个生产者或消费者能够生产或者消费的最大数目
#define BUFFER_SIZE 5 // 缓冲区的最大数目

// sem_t 用于声明信号量
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
long buffer[BUFFER_SIZE];
// pthread_mutex_t 线程互斥量，用于线程加锁
pthread_mutex_t mutex;

void *producer(void *pno) {
  long item;
  for (int i = 0; i < MAX_ITEMS; i++) {
    item = random();
    // sem_getvalue 获取信号量的值，获取失败时会返回 -1
#ifdef DEBUG_MODE
    op = sem_getvalue(&empty, &sem_v);
    printf("Before wait, empty sema value: %d\n", sem_v);
    if (op < 0) {
      printf("error: %s\n", strerror(errno));
    }
#endif
    // sem_wait - 对信号量的值进行 -1 的原子操作 (加锁)
    // 如果操作之前信号量的值大于 0，函数立即返回
    // 如果操作之前信号量的值等于 0，那么调用就会被阻塞，直到信号量可以执行 -1 操作
    sem_wait(&empty);
#ifdef DEBUG_MODE
    op = sem_getvalue(&empty, &sem_v);
    printf("After wait, empty sema value: %d\n", sem_v);
    if (op < 0) {
      printf("error: %s\n", strerror(errno));
    }
#endif
    // 在对缓冲区 (临界区) 进行操作时，进行加锁
    pthread_mutex_lock(&mutex);
    buffer[in] = item;
    printf("Producer %d: Insert Item %ld at %d\n", *((int *) pno), buffer[in], in);
    in = (in + 1) % BUFFER_SIZE;
    pthread_mutex_unlock(&mutex);
    // sem_post - 对信号量的值执行 +1 的原子操作 (解锁)，如果该操作导致信号量的值大于 1
    // 那么 sem_wait 阻塞的线程会被重新唤醒
    sem_post(&full);
  }
}
void *consumer(void *cno) {
  for (int i = 0; i < MAX_ITEMS; i++) {
#ifdef DEBUG_MODE
    op = sem_getvalue(&full, &sem_v);
    printf("Before wait, full sema value: %d\n", sem_v);
    if (op < 0) {
      printf("error: %s\n", strerror(errno));
    }
#endif
    sem_wait(&full);
#ifdef DEBUG_MODE
    op = sem_getvalue(&full, &sem_v);
    printf("After wait, full sema value: %d\n", sem_v);
    if (op < 0) {
      printf("error: %s\n", strerror(errno));
    }
#endif
    pthread_mutex_lock(&mutex);
    long item = buffer[out];
    printf("Consumer %d: Remove Item %ld from %d\n", *((int *) cno), item, out);
    out = (out + 1) % BUFFER_SIZE;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
  }
}

int main() {
  // pthread_t 声明线程 ID
  pthread_t pro[5], con[5];
  // int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
  // 初始化一个互斥锁，如果传入的属性为空，则按默认方式初始化一个互斥锁
  pthread_mutex_init(&mutex, NULL);
  // int sem_init(sem_t *sem, int pshared, unsigned int value);
  // sem_init 创建信号量
  // pshared 控制信号量的类型，如果其值为 0，就表示这个信号量是当前进程的局部信号量，否则信号量就可以在多个进程之间共享
  // value 为信号量的初始值
  sem_init(&empty, 0, BUFFER_SIZE);
  sem_init(&full, 0, 0);

  // 编号，标记各个线程
  int nos[5] = {1, 2, 3, 4, 5};

  for (int i = 0; i < 5; i++) {
    // 启动生产者线程
    pthread_create(&pro[i], NULL, (void *) producer, (void *) &nos[i]);
  }
  for (int i = 0; i < 5; i++) {
    // 启动消费者线程
    pthread_create(&con[i], NULL, (void *) consumer, (void *) &nos[i]);
  }

  for (int i = 0; i < 5; i++) {
    // 等待线程退出
    pthread_join(pro[i], NULL);
  }
  for (int i = 0; i < 5; i++) {
    pthread_join(con[i], NULL);
  }

  // 销毁互斥量
  pthread_mutex_destroy(&mutex);
  // 销毁信号量
  sem_destroy(&empty);
  sem_destroy(&full);

  return 0;
}
