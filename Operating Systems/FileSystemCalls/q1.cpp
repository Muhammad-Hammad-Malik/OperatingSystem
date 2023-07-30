#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
        pid_t id1;
        pid_t id2;
	char *line=argv[1];
	id1=vfork();
	if(id1<0)
	{
	  printf("ERROR \n");
	}
	
	if(id1==0)
	{
        printf("\n \n IN FIRST CHILD \n");
	char* args[]={"./temp.exe",argv[1],NULL};
	char *xx ="./temp.exe";
        execv(xx,args);
	}
	id2=vfork();
	if(id2<0)
	{
	  printf("ERROR");
	}
	if(id2==0)
	{
	  sleep(1);
	  printf("\n \n IN SECOND CHILD \n");
	  printf("the process ID is %d",getpid());
	  exit(0);
	}
	if((id1>0)&&(id2>0))
	{
	  wait(NULL);
	  wait(NULL);
	  printf("\n \n IN PARENT PROCESS ALL CHILDREN HAVE TERMINATED");
	}

}