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
  int nsize;
  int arr[6] = {1,2,3,4,5,6};
  write(fd,arr,sizeof(arr));
  sleep(5);
  int sum;
  read(fd,&sum,sizeof(nsize));
  printf(" THE SUM OF ARRAY PASSED BACK IS  \n %d",sum);
  close(fd);
  return 0;
}