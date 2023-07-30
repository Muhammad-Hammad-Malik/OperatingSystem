#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc,char *argv[])
{
  char *pipe_name = argv[1];
  int fd = open(pipe_name,O_RDWR);
  int asize;
  int arr[6];
  read(fd,&arr,sizeof(arr));
  printf("ARRAY PASSED TO CHILD\n");
  int sum = 0;
  for (int i = 0; i<6; i++) 
  {
    sum = sum + arr[i];
  }
  write(fd,&sum,sizeof(asize));
  close(fd);
  return 0;
}
  