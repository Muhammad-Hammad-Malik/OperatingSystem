#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main() 
{   
        pid_t p;
        p = fork();
	if(p<0)
	{
	  printf("ERROR");
	}
	if(p==0)
	{
	  wait(NULL);
	  printf("IN CHILD\n");
	  printf("process_ID=  %d\n" , getpid());
	  printf(" parent_process_ID=  %d\n" , getppid());
	  printf("\n");
	}
	if(p>0)
	{
	  printf("IN PARENT\n");
	  printf("process_ID=  %d\n" , getpid());
	  printf("child_process_ID=  %d\n" , p);
	  printf("\n");
	}
	 while (wait(NULL) > 0); 
}	
	
