#include <stdio.h>

char *strerror(int error) {
  static char message[30];

  if (error >= 0) {
    return ((char *) strerror(error));
  }

  sprintf(message, "Unknown error (%d)", error);
  return (message);
}
