#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#define KEY 99999
int main() 
{
    int id = shmget(KEY, 0, 0);
    if(id < 0) 
    {
        perror("Error accessing shared memory");
        exit(1);
    }
    int *shm = (int*) shmat(id, NULL, 0);
    if(shm == NULL)
    {
        perror("Error attaching to shared memory");
        exit(1);
    }
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        sum = sum + shm[i];
    }
    int avg =  sum / 10;
    printf("SUM IS : %d\n", sum);
    printf("Average: IS : %d.\n", avg);
    shmdt(shm);
    shmctl(id, IPC_RMID, NULL);
    return 0;
}