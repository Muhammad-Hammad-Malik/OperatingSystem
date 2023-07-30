#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *worker_thread1(void *arg)
{
  printf("THE THREAD ID IS %ld \n",pthread_self());
  printf("THE PROCESS ID IS %d \n",getpid());
}

int main()
{
    int n = 5;
    pthread_t my_thread1;
    for (int a=0;a<n;a++)
    {
      int ret = pthread_create(&my_thread1, NULL, &worker_thread1, NULL);
      if (ret != 0)
      {
          printf("Error creating thread\n");
          exit(EXIT_FAILURE);
      }
    }
    pthread_exit(NULL);
}
