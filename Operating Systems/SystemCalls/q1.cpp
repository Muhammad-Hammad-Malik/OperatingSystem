#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
	string finder=argv[1];
	string str;
	ifstream fin;
	int count=0;
	fin.open(finder);
	finder=argv[2];
	while(!fin.eof())
	{
		fin>>str;
		if(str==finder)
		{
			count++;
		}
	}
	fin.close();
	cout<<"the total number of repitions of string is "<<count;
	return 0; 
}
