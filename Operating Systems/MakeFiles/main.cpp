#include "Header.h"
int main()
{
	int arr[10] = { 3,2,1,0,5,4,7,6,9,8 };
	int size = 10;
	bool flag = 0;
	sort(arr, size, flag);
	system("pause");
	print(arr, size);
}