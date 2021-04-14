#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  fd_set rfds;
  struct timeval tv;
  int ret;

  /* Watch stdin (fd 0) to see when it has input. */
  FD_ZERO(&rfds);
  FD_SET(0, &rfds);

  /* Wait up to five seconds. */
  tv.tv_sec = 5;
  tv.tv_usec = 0;

  ret = select(1, &rfds, NULL, NULL, &tv);
  /* Don't rely on the value of tv now! */

  if (ret == -1) {
    perror("select()");
  } else if (ret) {
    printf("Data is available now.\n");
    printf("FD_ISSET(0, &rfds) = %d", FD_ISSET(0, &rfds));
  } else {
    printf("No data within five seconds.\n");
  }
  exit(EXIT_SUCCESS);
}
