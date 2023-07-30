#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[]) 
{   
	char ch;
	FILE *f1 ,*f2;
	f1 =fopen(argv[1],"r");
	f2 =fopen(argv[2],"w");
	if(f1 == NULL || f2 ==NULL)
	{
		printf("error openiing file");
		return 0;
	}
	while((ch=getc(f1))!=EOF)
	{
		if(isdigit(ch))
		{
			putc(ch,f2);
		}
	}
	fclose(f1);
	fclose(f2);
    return 0;
}
