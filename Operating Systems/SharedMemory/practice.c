#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  char *file1 = argv[1];
  char *file2 = argv[2];
  int f1 = open(file1,O_RDONLY);
  int f2 = open(file2,O_WRONLY);
  if((f1==-1)|| (f2==-1))
  {
    printf("ERROR IN OPENING FILES");
    exit(0);
  }
  dup2(f1,1);
  dup2(f2,2);
  char arr[100];
  read(1,&arr,100);
  int asize =0;
  for(int a =0;a<100;a++)
  {
    if (arr[a]=='$')
    {
      break;  
    }
    asize++;
  }
  
  write(2,&arr,asize);
  close(f1);
  close(f2);
}