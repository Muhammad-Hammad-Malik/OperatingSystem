#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
  int p1[2];
  int p2[2];
  int p3[2];
  int p4[2];
  int data;
  printf("Enter an integer: ");
  scanf("%d",&data);
  pid_t i1;
  pid_t i2;
  if(pipe(p1)<0)
  { 
    perror("PIPE ERROR");
    exit(1);
  }
  if(pipe(p2)<0)
  { 
    perror("PIPE ERROR");
    exit(1);
  }
  if(pipe(p3)<0)
  { 
    perror("PIPE ERROR");
    exit(1);
  }
  if(pipe(p4)<0)
  { 
    perror("PIPE ERROR");
    exit(1);
  }
  i1=fork();
  i2=fork();
  if(i1<0)
  {
    perror("FORK ERROR");
  }
  if(i2<0)
  {
    perror("FORK ERROR");
  }
  if(i1==0)
  {
    int value;
    close(p1[1]);
    read(p1[0],&value,sizeof(value));
    close(p1[0]);
    int factorial = value;
    for(int a=value-1;a>0;a--)
    {
      factorial=factorial*a;
    }
    close(p2[0]);
    write(p2[1],&factorial,sizeof(factorial));
    close(p2[1]);
    exit(0);
  }
  if(i2==0)
  {
    int value1;
    close(p3[1]);
    read(p3[0],&value1,sizeof(value1));
    close(p3[0]);
    int square = value1*value1;
    close(p4[0]);
    write(p4[1],&square,sizeof(square));
    close(p4[1]);
    exit(0);
  }
  if((i1>0)&&(i2>0))
  {
  write(p1[1],&data,sizeof(data));
  write(p3[1],&data,sizeof(data));
  close(p1[0]);
  close(p1[1]);
  close(p3[0]);
  close(p3[1]);
  wait(NULL);
  wait(NULL);
  int result;
  int result2;
  read(p2[0],&result,sizeof(result));
  read(p4[0],&result2,sizeof(result2));
  close(p2[0]);
  close(p2[1]);
  close(p4[0]);
  close(p4[1]);
  printf("the factorial is  %d",result);
  printf("  the square is %d",result2);
  }
 } 
  
