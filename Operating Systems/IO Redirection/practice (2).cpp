#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#define KEY 99999
int main(int argc, char *argv[]) 
{
    
    int arr[10];
    for(int i=0;i<10;i++)
    {
      arr[i]=i;
    }
    int id = shmget(KEY, sizeof(int) * 10, 0666 | IPC_CREAT);
    if(id < 0) 
    {
        perror("Error creating shared memory");
        exit(1);
    }
    int *shm = (int*) shmat(id, NULL, 0);
    if(shm == NULL)
    {
        perror("Error attaching to shared memory");
        exit(1);
    }
    memcpy(shm, arr, sizeof(int) * 10);
    shmdt(shm);
    printf("Data sent to server via shared memory.\n");
    return 0;
}