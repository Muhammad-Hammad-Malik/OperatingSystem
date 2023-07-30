#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
	string arr;
    fstream myFile("test.txt",ios::in | ios::out | ios::trunc);
    cout<<"enter a string to input in file"<<endl;
    cin>>arr;
    myFile <<arr;
    int size=arr.size();
    //int position = myFile.tellp();
    int position=0;
    char ax;
    int x=0;
    for(int a=0;a<size*2;a++)
    {
   		if(a%2==1)
   		{
	    	cout<<"enter a character ";
	    	cin>>ax;
	    	myFile.seekp(position-0);
	    	cin.ignore();
	    	myFile<<ax;
	    	position=position+1;
	    }
	    else
	    {
	    	myFile.seekp(position-0);
	    	myFile<<arr[x];
	    	x++;
	    	position++;
		}
	}
    myFile.close();
}