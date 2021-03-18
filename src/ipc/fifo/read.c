#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FIFO_ID "/tmp/FIFO_TEST"
#define BUFFER_SIZE 2048
#define perror() { printf("error: %s\n", strerror(errno)); exit(1);}

int main(void) {
  int fd;
  ssize_t n;
  char buf[BUFFER_SIZE];

  if ((fd = open(FIFO_ID, O_RDONLY)) < 0) {
    perror()
  }

  while ((n = read(fd, buf, BUFFER_SIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      exit(1);
    }
  }
  close(fd);

  return 0;
}
