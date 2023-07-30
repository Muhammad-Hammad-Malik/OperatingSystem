#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;
int main() 
{   
        pid_t p;
        p = fork();
	if(p<0)
	{
	  cout<<"error"<<endl;
	}
	if(p==0)
	{ 
	  int number;
	  cout<<"enter a number to print its factorial";
	  cin>>number;
	  int factorial=number;
	  for(int a=factorial-1;a>0;a--)
	  {
	    factorial=factorial*a;  
	  }
          cout<<"factorial is = " << factorial <<endl;
	}
	if(p>0)
	{
	  int status = 10;
          wait(&status); 
          cout << "Child process exited with status " << status << endl;
          exit(0);
	} 
}	
	
