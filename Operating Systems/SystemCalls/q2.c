#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc, char *argv[]) 
{   
        pid_t p;
        FILE *f1;
	f1 = fopen(argv[1],"r");  
	if(f1==NULL)
	{
		printf("wrong");
	}
	int i=0;
	char ch;
	int temp=0;
	p = fork();
	if(p<0)
	{
	  printf("ERROR");
	}
	if(p==0)
	{
	  while((ch=getc(f1))!=EOF)
	  {
          temp = (int)(ch);
          if((!(temp>=48 && temp<=57))&&(!(temp>=65 && temp<=90))&&(!(temp>=97 && temp<=122)))
	    {
	      printf("%c",ch);
	      printf(" ");	    
	    }
	  }
	}
	if(p>0)
	{
	  wait(NULL);
	  printf("CHILD HAS DONE HIS JOB PARENT CALLED NOW");
	}
}
