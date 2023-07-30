#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[] )
{
        FILE *f1;
        char *arrf = argv[1];
	f1 = fopen(argv[1],"r");
	if(f1==NULL)
	{
	  printf("not");
	  exit(0);
    }
	int size=0; 
	char str[50];   
	int i=0;   
	int ir=0;
	char ch;
	while((ch=getc(f1))!=EOF)
	{
	  str[ir]=ch;
	  ir++;
	}
	fclose(f1);
	while(str[i]!='$')
	{
		size++;
		i++;
	}
	char newstr[50];
	
	for(int a=0;a<size;a++)
	{
		newstr[a]='$';
	}

	for(int a=0;a<size;a++)
	{
		if((str[a]=='a')||(str[a]=='A')||(str[a]=='e')||(str[a]=='E')||(str[a]=='i')||(str[a]=='I')||(str[a]=='o')||(str[a]=='O')||(str[a]=='u')||(str[a]=='U'))
		{
			newstr[a]=str[a];
		}
	}
	int loc=0;
	for(int a=size-1;a>=0;a--)
	{
		if((str[a]=='a')||(str[a]=='A')||(str[a]=='e')||(str[a]=='E')||(str[a]=='i')||(str[a]=='I')||(str[a]=='o')||(str[a]=='O')||(str[a]=='u')||(str[a]=='U'))
		{
		
		}	
		else
		{
			
			while(newstr[loc]!='$')
			{
				loc++;	     
			}	
			newstr[loc]=str[a];
		}
	}
	printf("\n");
	for(int a=0;a<size;a++)
	{
		printf("%c",newstr[a]);
	}
	return 0;
}