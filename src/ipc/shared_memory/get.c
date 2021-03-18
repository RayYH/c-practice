#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define STORAGE_ID "/SHM_TEST"
#define STORAGE_SIZE 32

int main() {
  int fd;
  char data[STORAGE_SIZE];
  pid_t pid;
  void *addr;

  // pid_t getpid(void);
  // 获取当前进程的 PID
  pid = getpid();

  fd = shm_open(STORAGE_ID, O_RDONLY, S_IRUSR | S_IWUSR);
  if (fd == -1) {
    perror("open");
    return 10;
  }

  addr = mmap(NULL, STORAGE_SIZE, PROT_READ, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    return 30;
  }

  // 拷贝数据，addr -> data
  memcpy(data, addr, STORAGE_SIZE);

  printf("PID %d: Read from shared memory: \"%s\"\n", pid, data);

  return 0;
}
