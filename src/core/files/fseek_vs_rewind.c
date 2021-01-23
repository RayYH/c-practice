#include "core.h"
#include "files.h"

/**
 * In C, fseek() should be preferred over rewind(). The rewind function sets
 * the file position indicator for the stream pointed to by stream to the
 * beginning of the file. It is equivalent to
 *            (void)fseek(stream, 0L, SEEK_SET)
 * except that the error indicator for the stream is also cleared.
 */
int main(void) {
  FILE *fp = fopen(tmp_file, "r");

  if (fp != NULL) {
    rewind(fp);
    if (fseek(fp, 0L, SEEK_SET) != 0) {
      // do something else
    }
  }
  fclose(fp);
}
