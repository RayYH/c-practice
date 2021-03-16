#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define FIFO_ID "/tmp/FIFO_TEST"
#define BUFFER_SIZE 2048
#define perror() { printf("error: %s\n", strerror(errno)); exit(1); }

int main(void) {
  remove(FIFO_ID);
  int fd;
  ssize_t n;
  size_t nbytes;
  char buf[BUFFER_SIZE];

  mkfifo(FIFO_ID, 0666);
  fd = open(FIFO_ID, O_RDONLY | O_WRONLY);
  if (fd < 0) {
    printf("\n %s \n", strerror(errno));
    return 0;
  }

  while ((n = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0) {
    nbytes = write(fd, buf, n);
    if (nbytes != n) {
      printf("nbytes: %ld", nbytes);
      perror()
    }
  }
  close(fd);

  return 0;
}
