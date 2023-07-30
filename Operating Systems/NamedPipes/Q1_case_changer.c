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
  int xsize = 100;
  int asize;
  char arr[100];
  read(fd,&arr,100);
  printf(" THE ORIGNAL ARRAY PASSED TO CHILD IS \n %s",arr);
  for (int i = 0; i<100; i++) 
  {
    if(arr[i] >= 'a' && arr[i] <= 'z') 
    {
         arr[i] = arr[i] - 32;
    }
    else if(arr[i] >= 'A' && arr[i] <= 'Z') 
    {
         arr[i] = arr[i] + 32;
    }
  }
  write(fd,&arr,100);
  close(fd);
  return 0;
}
  