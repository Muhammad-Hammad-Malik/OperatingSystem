#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc,char *argv[])
{
  char *pipe_name = argv[1];
  int fd = open(pipe_name,O_RDWR);
  char arr[100] ="HeLlo";
  write(fd,arr,100);
  sleep(5);
  char arr2[100];
  read(fd,arr2,100);
  printf(" THE ORIGNAL ARRAY PASSED BACK TO PARENT IS \n %s",arr2);
  close(fd);
  return 0;
}