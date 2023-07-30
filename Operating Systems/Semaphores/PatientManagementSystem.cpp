#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdbool.h>

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
int PTC = 0;  // potential covd patients
int CP = 0;   // covid positive cases
int Fp = 0;  // flu positive cases

void recoverpatient()
{
  bool test = true;
      while(test==true)
      {
	if(rand()%2==0)
	  {
	    if(rand()%2==0)
	    {
        	test=false;		
	    }
	  }		
      }
      wait(&PTC);
      printf("COVID PATIENT RECOVERED \n");
}


void *worker_thread1(void *arg)
{
    int tcase = rand() ;
    if(tcase %2 == 0)
    {
    	signal(&Fp); // flu patient
    	wait(&PTC);
	}
	if(tcase %2 == 1)
	{
		signal(&CP); // covid patient
		recoverpatient();
	}
	pthread_exit(NULL);
}

int main()
{
    srand(time(0));  
    int n ;
    printf("ENTER NO OF STUDNETS");
    scanf("%d",&n);
    PTC = n;
    printf("INITIAL POTENTICAL PATIENTS ARE %d \n",PTC);
    pthread_t my_thread_array[n];
    for (int a = 0; a < n; a++)
    {
        int ret = pthread_create(&my_thread_array[a], NULL, &worker_thread1, NULL);
        if (ret != 0)
        {
            printf("Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }
    for (int a = 0; a < n; a++)
    {
        pthread_join(my_thread_array[a], NULL);
    }
    printf("THE POTENTIAL C PATIENTS ARE %d \n",PTC);
    printf("THE FLU PATIENTS ARE %d \n",Fp);
    printf("THE COVID PATIENTS ARE %d \n",CP);
    return 0;
}