#include <stdio.h>
#include <sys/stat.h>

long offset(void *baseaddr, void *addr)
{
  return (long)(addr - baseaddr);
}

int main(int argc, char *argv[])
{
  struct stat st;

  printf("st       = %-16lX (%d)\n", &st, sizeof(st));
  printf("st_dev   = %2d (%d)\n", offset(&st, &st.st_dev)  , sizeof(st.st_dev));
  printf("st_ino   = %2d (%d)\n", offset(&st, &st.st_ino)  , sizeof(st.st_ino));
  printf("st_mode  = %2d (%d)\n", offset(&st, &st.st_mode) , sizeof(st.st_mode));
  printf("st_nlink = %2d (%d)\n", offset(&st, &st.st_nlink), sizeof(st.st_nlink));
  printf("st_uid   = %2d (%d)\n", offset(&st, &st.st_uid)  , sizeof(st.st_uid));
  printf("st_gid   = %2d (%d)\n", offset(&st, &st.st_gid)  , sizeof(st.st_gid));
  printf("st_size  = %2d (%d)\n", offset(&st, &st.st_size) , sizeof(st.st_size));

  return 0;
}
