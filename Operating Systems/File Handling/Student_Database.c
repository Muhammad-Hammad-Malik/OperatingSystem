#include <stdio.h>
#include <stdlib.h>

void write_data()
{
	FILE *f1;
	f1 = fopen("file.txt","a+");
	if(f1==NULL)
	{
		printf("ERROR      !!!!  \n");
	}
	FILE *f2;
	f2 = fopen("size.txt","r");
	if(f2==NULL)
	{
		printf("ERROR      !!!!  \n");
	}
	char size;
	size=getc(f2);
	fclose(f2);
	int s1 =size-'0';
	s1++;
	size=s1 +'0';
	FILE *f3;
	f3 = fopen("size.txt","w");
	putc(size,f3);
	fclose(f3);
	char name[60];
	char email[60];
	char roll[60];
	char ch;
	printf("enter your name \n");
	scanf("%s",name); 
	while ((getchar()) != '\n'); 
	printf("enter your email \n");
	scanf("%s",email);
	while ((getchar()) != '\n');
	printf("enter roll number \n");
	scanf("%s",roll);
	while ((getchar()) != '\n');
	fprintf(f1,"\n%s",name);
	fprintf(f1,"\n%s",email);
	fprintf(f1,"\n%s",roll);
	fclose(f1);
}

void read_data1()
{
	FILE *f1;
	char x;
	f1 = fopen("file.txt","r");
	if(f1==NULL)
	{
		printf("ERROR      !!!!  \n");
	}
	while (!feof(f1)) 
	{
    	x = fgetc(f1);
    	printf("%c",x);
    }
    fclose(f1);
	
}

void read_data()
{
	FILE *f1;
	f1 = fopen("file.txt","r");
	char name[60];
	char email[60];
	char roll[60];
	FILE *f2;
	f2 = fopen("size.txt","r");
	if(f2==NULL)
	{
		printf("ERROR      !!!!  \n");
	}
	char size;
	size=getc(f2);
	fclose(f2);
	int choice;
	printf("Which student's record you want to get the limit is :? 1 -> %c",size);
	scanf("%d",&choice);
	int s1 =size-'0';
	while((choice<=0)||(choice>s1))
	{
		printf("wrong input enter again ");
		scanf("%d",&choice);
	}
	for(int a=1;a<=s1;a++)
	{
		fscanf(f1,"%s",name);
		fscanf(f1,"%s",email);
		fscanf(f1,"%s",roll);
		if(a==choice)
		{
			printf("\n %s",name);
			printf("\n %s",email);
			printf("\n %s",roll);
		}
	}
	return;
}

void copy_temp()
{
	FILE *f1;
	f1 = fopen("temp.txt","r");
	FILE *f2;
	f2 = fopen("file.txt","w");
	char ch = fgetc(f1);
    while (ch != EOF)
    {
        fputc(ch,f2);
        ch = fgetc(f1);
    }
    fclose(f1);
    fclose(f2);
}
void delete_data()
{
	FILE *f1;
	f1 = fopen("file.txt","r");
	char name[60];
	char email[60];
	char roll[60];
	FILE *f2;
	f2 = fopen("size.txt","r");
	if(f2==NULL)
	{
		printf("ERROR      !!!!  \n");
	}
	char size;
	size=getc(f2);
	fclose(f2);
	int choice;
	printf("Which student's record you want to delete the limit is :? 1 -> %c",size);
	scanf("%d",&choice);
	int s1 =size-'0';
	while((choice<=0)||(choice>s1))
	{
		printf("wrong input enter again ");
		scanf("%d",&choice);
	}
	FILE *f3;
	f3 = fopen("temp.txt","w");
	for(int a=1;a<=s1;a++)
	{
		fscanf(f1,"%s",name);
		fscanf(f1,"%s",email);
		fscanf(f1,"%s",roll);
		if(a!=choice)
		{
			fprintf(f3,"\n%s",name);
			fprintf(f3,"\n%s",email);
			fprintf(f3,"\n%s",roll);
		}
	}
	FILE *f4;
	f4 = fopen("size.txt","r");
	if(f4==NULL)
	{
		printf("ERROR      !!!!  \n");
	}
	char size2;
	size2=getc(f4);
	fclose(f4);
	int s2 =size-'0';
	s2--;
	size2=s2 +'0';
	FILE *f5;
	f5 = fopen("size.txt","w");
	putc(size2,f5);
	fclose(f5);
	fclose(f1);
	fclose(f3);
	copy_temp();
}
int main() 
{   
	int decision=10;  // random
	while(decision!=3) 
	{
		printf("enter input ? 0 for insertion 1 for retrieval and 2 for deletion 3 for termination \n");
		scanf("%d",&decision);
		if(decision==0)
		{
			write_data();
		}
		else if(decision==1)
		{
			read_data();
		}
		else if(decision==2)
		{
			delete_data();
		}
		else if(decision==3)
		{
			
		}
		else
		{
			printf("wrong input enter again");
			scanf("%d",&decision);
		}
	}
	return 0;
}