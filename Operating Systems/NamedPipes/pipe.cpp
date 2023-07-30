#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#define PIPE_PERM (S_IRUSR | S_IWUSR)
int main(int argc,char *argv[])
{
  char* pipe_name =argv[1];
  int status = mkfifo(pipe_name,PIPE_PERM);
  printf("%d \n",status);
  return 0;
}
