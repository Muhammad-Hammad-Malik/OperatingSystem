#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{   
    FILE *f1;
	f1 = fopen(argv[1],"r");  
	int i=0;
	char ch;
	int temp=0;
	while((ch=getc(f1))!=EOF)
	{
            temp = (int)(ch);
            if(temp>=48 && temp<=57)
	    {
                i++;
	    }
	}
	printf("TOTAL NUMBERS IN TEXT ARE: %d",i);
	return 0;
}