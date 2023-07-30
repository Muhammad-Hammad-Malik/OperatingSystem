#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) 
{   
	int a;
	int b;
	int sum;
	int avg;
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	sum = a+b;
	avg =sum/2;
	printf("THE SUM IS  %d\n",sum);
	printf("THE AVERAGE IS  %d./\n",avg);
    return 0;
}
