#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

int main()
{
  int p1[2];
  int p2[2];
  FILE *f1 ,*f2;
  pid_t i1;
  if(pipe(p1)<0)
  { 
    printf("PIPE ERROR"); 
    exit(1);
  }
  if(pipe(p2)<0)
  { 
    printf("PIPE ERROR");
    exit(1);
  }
  i1=fork();
  if(i1<0)
  {
    perror("FORK ERROR");
  }
  if(i1==0)
  {
    char str[100];
    close(p1[1]);
    read(p1[0],&str,100);
    close(p1[0]);
    close(p2[0]);
    write(p2[1],&str,100);
    close(p2[1]);
    exit(0);
  }
  if((i1>0))
  {
  int fd = open("test.txt",O_RDONLY);
  char arr[100];
  read(fd,&arr,100);
  close(fd);
  int len=0;
  while(arr[len]!='\n')
  {
    len++;
  }
  for(int i=0;i<=len;i++)
  {
          if ((arr[i]=='!' || arr[i]=='@' || arr[i]=='#' || arr[i]=='$' || arr[i]=='%' || arr[i]=='^' || arr[i]=='&' || arr[i]=='*' || arr[i]=='_'))
	  {
              arr[i]=' ';
          }
  }
  write(p1[1],&arr,100);
  close(p1[0]);
  close(p1[1]);
  wait(NULL);
  char arr2[100];
  read(p2[0],&arr2,100);
  int fd2 = open("output.txt",O_WRONLY);
  int size=0;
  while(arr2[size]!='\n')
  {
    size++;
  }
  write(fd2,arr2,size);
  close(fd2);
  close(p2[0]);
  close(p2[1]);
  }
 } 