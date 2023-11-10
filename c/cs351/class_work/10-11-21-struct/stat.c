#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: stat <filename>\n");
    return 0;
  }

  struct stat st;

  if (stat(argv[1], &st) < 0) {
    perror("stat");
    return 1;
  }

  printf("device = %d\n", st.st_dev);
  printf("inode# = %d\n", st.st_ino);
  printf("mode   = %d\n", st.st_mode);
  printf("nlink  = %d\n", st.st_nlink);
  printf("uid    = %d\n", st.st_uid);
  printf("gid    = %d\n", st.st_gid);
  printf("size   = %ld\n", st.st_size);
  return 0;
}
