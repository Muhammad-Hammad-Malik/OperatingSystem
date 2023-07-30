#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
using namespace std;
int timer = 0;
void signal_handler(int sig_num) 
{
  cout << "THE TOTAL TIME IS " << timer << endl;
}
int main()
{
  int totaltime;
  int laptime;
  int no_of_laps;
  pid_t id;
  cout << "Enter the number of laps: ";
  cin >> no_of_laps;
  cout << "Enter the time of each lap: ";
  cin >> laptime;
  id = fork();
  if (id < 0)
  {
    cout << "Error occurred" << endl;
  }
  if (id == 0)
  {
    for (int iter = 0; iter < no_of_laps; iter++)
    {
      int sec = 0;
      for (int i = 0; i < laptime; i++)
      {
        sec++;
        cout << "LAP: " << iter + 1;
        cout << "  sec :" << sec << endl;
        sleep(1);
      }
    }
    kill(getppid(), SIGINT);
    exit(0);
  }
  if (id > 0)
  {
    totaltime = laptime * no_of_laps;
    timer = totaltime;
    signal(SIGINT, signal_handler);
    cout << "Waiting for signal..." << endl;
    pause();
    wait(NULL);
  }
  
  return 0;
}
