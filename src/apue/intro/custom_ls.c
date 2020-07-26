#include "apue.h"
#include <dirent.h>

// dirent.h - format of directory entries
int main(int argc, char *argv[]) {

  DIR *dp;
  struct dirent *dir_ptr;

  if (argc != 2)
    err_quit("usage: ls directory_name");

  if ((dp = opendir(argv[1])) == NULL) {
    err_sys("can't open %s", argv[1]);
  }

  while ((dir_ptr = readdir(dp)) != NULL) {
    printf("%s\n", dir_ptr->d_name);
  }

  closedir(dp);
  exit(0);
}