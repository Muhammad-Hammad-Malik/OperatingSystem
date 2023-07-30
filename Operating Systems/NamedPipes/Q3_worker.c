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
  char o;
  read(fd,&o,sizeof(o));
  sleep(2);
  int asize;
  int arr[2];
  read(fd,&arr,sizeof(arr));
  printf("ARRAY PASSED TO CHILD\n");
  int sum = 0;
  if(o=='+')
  {
    sum = arr[0]+arr[1];  
  }
  else if(o=='-')
  {
    sum = arr[0]-arr[1];
  }
  else if(o=='/')
  {
    sum = arr[0]/arr[1];
  }
  else if(o=='*')
  {
    sum = arr[0]*arr[1];
  }
  else
  {
    printf("WRONG OPERATOR");
  }
  write(fd,&sum,sizeof(asize));
  close(fd);
  return 0;
}
  