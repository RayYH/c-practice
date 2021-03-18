#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define STORAGE_ID "/SHM_TEST"
#define STORAGE_SIZE 32
#define DATA "Hello, World! From PID %d"

int main() {
  int res;
  int fd;
  unsigned int len;
  pid_t pid;
  void *addr;
  char data[STORAGE_SIZE];

  pid = getpid();
  sprintf(data, DATA, pid);

  // int shm_open(const char *name, int oflag, mode_t mode);
  // shm_open - 创建新的或者打开已有的共享内存对象
  // O_RDONLY - 表示以只读方式打开
  // O_CREAT - 不存在则创建
  // S_IRUSR - 文件所属者的读权限位
  // S_IWUSR - 文件所属者地写权限位
  // 推荐阅读：https://stackoverflow.com/questions/14055755/whats-the-meaning-of-i-in-s-irusr
  fd = shm_open(STORAGE_ID, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  if (fd == -1) {
    perror("open");
    return 10;
  }

  // int truncate(const char *path, off_t length);
  // 这里 ftruncate 的作用相当于设置内存对象的长度，默认值是 0
  res = ftruncate(fd, STORAGE_SIZE);
  if (res == -1) {
    perror("ftruncate");
    return 20;
  }

  // void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
  // mmap - 将共享内存映射到进程的地址空间
  // addr - 设置为 NULL 表示由操作系统设置一个新页来复制该共享内存
  // length - 映射内存大小
  // prot - 页的权限控制，PROT_EXEC/PROT_READ/PROT_WRITE/PROT_NONE
  // flags - 设置当前页的更新是否对其他进程可见，MAP_SHARED/MAP_PRIVATE/MAP_SHARED_VALIDATE(Linux)
  // fd - 共享内存后对应的文件描述符
  // 该操作成功的话，返回映射后的地址，失败的话，返回 MAP_FAILED，因此需要进行检查
  // 推荐阅读：https://man7.org/linux/man-pages/man2/mmap.2.html
  addr = mmap(NULL, STORAGE_SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    return 30;
  }

  // 拷贝数据，data -> addr
  len = strlen(data) + 1;
  memcpy(addr, data, len);

  // 等待某个进程读取共享内存中的数据
  sleep(2);

  // mmap 的方操作，用于清理所创建的映射，清理完成后对共享内存的访问都是非法的
  res = munmap(addr, STORAGE_SIZE);
  if (res == -1) {
    perror("munmap");
    return 40;
  }

  // shm_open 的反操作，用于移除 shm_open 创建的内存对象
  fd = shm_unlink(STORAGE_ID);
  if (fd == -1) {
    perror("unlink");
    return 100;
  }

  return 0;
}
