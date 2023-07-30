#include "Header.h"

void sort(int arr[],int size, bool order)
{
	if (order==0)
	{
		for (int a = 0; a < size-1; ++a) 
		{
			for (int i = 0; i < size - a-1; ++i)
			{
				if (arr[i] > arr[i + 1])
				{
					int temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}
	}
	else
	{
		for (int a = 0; a < size; ++a)
		{
			for (int i = 0; i < size - a; ++i)
			{
				if (arr[i] < arr[i + 1])
				{
					int temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}
	}

}
void highest(int arr[], int size, int n, bool order)
{
	if (order == 1)
	{
		cout << "the " << n << "th highest is " << arr[n - 1];
	}
	else
	{
		cout << "the " << n << "th highest is " << arr[size - n];
	}
}
void print(int arr[], int size)
{
	cout << endl;
	for (int a = 0;a < size;a++)
	{
		cout << " " << arr[a];
	}
	cout << endl;
}
