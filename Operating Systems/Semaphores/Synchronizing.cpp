#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
int array[20];
int index=0; // to access array 
int sig=1; // semaphore between A B and C for synchronization
int sig2= 1; // semaphore between C and D for synchronization
void wait(int* s) 
{
    while(*s<=0) 
    {
    	//do nothing
    }
    *s=*s-1;
}
void signal(int* s) 
{
        *s=*s+1;
}
int turn = 1; // strict alteration
void *worker_thread1(void *arg) // process A
{
		wait(&sig);
		FILE *fp;
	    fp = fopen("f1.txt", "r");
    	if (fp == NULL)
	 	{
        	perror("Error opener file1");
        	pthread_exit(NULL);
   	 	}

    	for (int i = 0; i < 10; i++)
		{
			while(turn!=1){};
        	fscanf(fp, "%d", &array[index]);
        	index++;
        	turn = 2;
    	}
}
void *worker_thread2(void *arg)  // process B
{
		FILE *fp1;
	    fp1 = fopen("f2.txt", "r");
    	if (fp1 == NULL)
	 	{
        	perror("Error opener file2");
        	pthread_exit(NULL);
   	 	}
    	for (int i = 0; i < 10; i++)
		{
			while(turn!=2){};
        	fscanf(fp1, "%d", &array[index]);
        	index++;
        	turn = 1;
    	}
    	signal(&sig);
}
int arr2[20];
void *worker_thread3(void *arg)  // process B
{
	wait(&sig2);
	wait(&sig);
	for (int a =0;a<20;a++)
	{
		arr2[a]=array[a];
	}
	signal(&sig2);
}
void *worker_thread4(void *arg)  // process B
{
		wait(&sig2);
		for(int a=0;a<20;a++)
        {
        	printf("%d \n",arr2[a]);
		}
		signal(&sig);
}

        
int main()
{
    	pthread_t my_thread1;
    	pthread_t my_thread2;
    	pthread_t my_thread3;
    	pthread_t my_thread4;
        int ret = pthread_create(&my_thread1, NULL, &worker_thread1, NULL);
        if (ret != 0)
        {
            printf("Error creating thread\n");
            exit(EXIT_FAILURE);
    	}
    	ret = pthread_create(&my_thread2, NULL, &worker_thread2, NULL);
        if (ret != 0)
        {
            printf("Error creating thread\n");
            exit(EXIT_FAILURE);
    	}
    	ret = pthread_create(&my_thread3, NULL, &worker_thread3, NULL);
        if (ret != 0)
        {
            printf("Error creating thread\n");
            exit(EXIT_FAILURE);
    	}
    	ret = pthread_create(&my_thread4, NULL, &worker_thread4, NULL);
        if (ret != 0)
        {
            printf("Error creating thread\n");
            exit(EXIT_FAILURE);
    	}
        pthread_join(my_thread4, NULL);

   		return 0;
}