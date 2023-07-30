#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *worker_thread1(void *arg)
{
  long int x = (long int) arg;
  int sum = 0;
  for(int a = 0; a <=x; a++)
  {
    sum += a;
  }
  printf("The summation of %ld is %d\n", x, sum);
  pthread_exit(NULL);
}

int main()
{
    long int n = 5;
    pthread_t my_thread1;
    int ret = pthread_create(&my_thread1, NULL, &worker_thread1, (void *) n);
    if (ret != 0)
    {
        printf("Error creating thread\n");
        exit(EXIT_FAILURE);
    }
    pthread_join(my_thread1, NULL); 
    pthread_exit(NULL);
}
