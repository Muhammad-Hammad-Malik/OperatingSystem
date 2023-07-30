#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;
int main()
{
  int totaltime;
  int laptime;
  int no_of_laps;
  pid_t id;
  cout<<"enter the number of laps : ";
  cin>>no_of_laps;
  cout<<"enter the time of each lap : ";
  cin>>laptime;
  for(int iter=0;iter<no_of_laps;iter++)
  {
    id=fork();
    if(id<0)
    {
      cout<<"error occurred";  
    }
    if(id==0)
    {
        int sec=0;
        for (int i = 0; i < laptime; i++)
	{
	  sec++;
	  cout << "LAP: " << iter + 1 << endl;
	  cout << "sec :" << sec << endl;
      	  sleep(1);
	  system("clear");
	}
	exit(0);
    }
    if(id>0)
    {
      wait(NULL);
      totaltime=totaltime+laptime;
      if(iter+1==no_of_laps)
      {
        int hour = totaltime/3600;
        totaltime = totaltime%3600;
        int min = totaltime/60;
        totaltime = totaltime%60;
        int sec = totaltime;
        cout<<"TOTAL TIME = "<<hour<<":"<<min<<":"<<sec;
      }
    }
  }
}
