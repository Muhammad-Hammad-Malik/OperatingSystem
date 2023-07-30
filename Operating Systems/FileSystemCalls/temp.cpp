#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;
int main(int argc, char *argv[])
{
       string line;
       line=argv[1];
       cout<<endl<<"THE SIZE OF STRING IS "<<line.size()<<endl;
       string temp = "";
       for (int i = 0; i < line.size(); ++i)
       {
           if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
	   {
               temp = temp + line[i];
           }
        }
        cout<<"THE MODIFIED STRING IS "<<temp<<endl;
}