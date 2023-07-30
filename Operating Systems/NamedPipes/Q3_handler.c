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
  char operatorx;
  printf("ENTER THE OPERATOR ");
  scanf("%c",&operatorx);
  write(fd,&operatorx,sizeof(operatorx));
  sleep(2);
  int arr[2]={10,4};
  write(fd,arr,sizeof(arr));
  sleep(5);
  int sum;
  int nsize;
  read(fd,&sum,sizeof(nsize));
  printf(" THE ANSWER OF ARRAY PASSED BACK IS  \n %d",sum);
  close(fd);
  return 0;
}