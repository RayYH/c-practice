#include "apue.h"

/**
 * Write "n" bytes to a descriptor.
 *
 * @param fd file descriptor
 * @param ptr message
 * @param n length
 * @return amount of written successfully, if error happens, returns -1
 */
ssize_t writen(int fd, const void *ptr, size_t n) {
  size_t n_left;
  ssize_t n_written;

  n_left = n;
  while (n_left > 0) {
    if ((n_written = write(fd, ptr, n_left)) < 0) {
      if (n_left == n) {
        // error, return -1
        return (-1);
      } else {
        // error, return amount written so far
        break;
      }
    } else if (n_written == 0) {
      break;
    }

    n_left -= n_written;
    ptr += n_written;
  }

  // returned value >= 0 (amount written so far)
  return (n - n_left);
}
