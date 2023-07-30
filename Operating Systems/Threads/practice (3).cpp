#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int evencount,oddcount,sumcount;
void *worker_thread1(void *arg)
{
    printf("THREAD ID = %ld",pthread_self());
    int x = *((int *) arg); 
    int sum = 0;
    int *arr = malloc(x * sizeof(int));
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < x; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    pthread_exit(arr);
}
int size = 0;
void *worker_thread2(void *arg)
{
    printf("THREAD ID = %ld",pthread_self());
    int *arr = (int *)arg;
    int count = 0;
    for (int i = 0; i < size; i++) 
    {
      if(arr[i]%2==0)
      {
        count++;
      }
    }
    evencount=count;
    pthread_exit(NULL);
}
void *worker_thread3(void *arg)
{
    printf("THREAD ID = %ld",pthread_self());
    int *arr = (int *)arg;
    int count = 0;
    for (int i = 0; i < size; i++) 
    {
      if(arr[i]%2==1)
      {
        count++;
      }
    }
    oddcount=count;
    pthread_exit(NULL);
}

void *worker_thread4(void *arg)
{
    printf("THREAD ID = %ld",pthread_self());
    FILE *f1;
    f1 = fopen("sum.txt","w");
    int *arr = (int *)arg;
    int sum = 0;
    for (int i = 0; i < size; i++) 
    {
      sum = sum + arr[i];
    }
    sumcount=sum;
    pthread_exit(NULL);
}

int main()
{
    int n = 5;
    printf("ENTER INTEGER TO GET INFO OF : ");
    scanf("%d",&n);
    size = n;
    pthread_t my_thread1;
    pthread_t my_thread2;
    pthread_t my_thread3;
    pthread_t my_thread4;
    int ret = pthread_create(&my_thread1, NULL, &worker_thread1, (void *) &n);
    if (ret != 0)
    {
        printf("Error creating thread\n");
        exit(EXIT_FAILURE);
    }
    void *temp;
    pthread_join(my_thread1,&temp);
    int *arr = (int *) temp;
    printf("THE FIBBONACI SERIES IS \n");
    for(int r=0;r<size;r++)
    {
      printf(" %d",arr[r]);
    }
    printf("\n");
    ret = pthread_create(&my_thread2, NULL, &worker_thread2,arr);
    if (ret != 0)
    {
        printf("Error creating thread\n");
        exit(EXIT_FAILURE);
    }
    pthread_join(my_thread2,NULL);
    printf("THE TOTAL NO OF EVEN ARE %d \n",evencount);
    ret = pthread_create(&my_thread3, NULL, &worker_thread3,arr);
    if (ret != 0)
    {
        printf("Error creating thread\n");
        exit(EXIT_FAILURE);
    }
    pthread_join(my_thread3,NULL);
    printf("THE TOTAL NO OF ODD ARE %d \n",oddcount);
    ret = pthread_create(&my_thread4, NULL, &worker_thread4,arr);
    if (ret != 0)
    {
        printf("Error creating thread\n");
        exit(EXIT_FAILURE);
    }
    pthread_join(my_thread4,NULL);
    printf("THE SUM OF series IS %d \n",sumcount);
    pthread_exit(NULL);
}
