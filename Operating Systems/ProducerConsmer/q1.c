#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <string.h>
#define SEM_NAME "/my_semaphore"
#define KEY 99999

int main()
{
    sem_t *sem;
    pid_t pid;
    int status;

    sem = sem_open(SEM_NAME, O_CREAT, 0644, 0);
    if (sem == SEM_FAILED)
    {
        perror("sem_open failed");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) 
    {
        // WRITER
        int id = shmget(KEY, sizeof(char) * 20, 0666 | IPC_CREAT);
        if(id < 0) 
        {
            perror("Error creating shared memory");
            exit(1);
        }
        char *shm = (char*) shmat(id, NULL, 0);

        FILE *fp;
        char str[20];
        int i, j;
        printf("Child process received signal.\n");
        fp = fopen("file.txt", "r");
        for (i = 0; i < 3; i++) 
        {
          printf("Reading %d:\n", i+1);
          for (j = 0; j < 20; j++)
          {
              str[j] = fgetc(fp);
          }
          memcpy(shm, str, sizeof(char) * 20);
          sem_post(sem);
        }  
        shmdt(shm);
        exit(0);
    }
    else
    {
        // READER
        int id = shmget(KEY, 0, 0);
        if(id < 0) 
        {
            perror("Error accessing shared memory");
            exit(1);
        }
        char *shm = (char*) shmat(id, NULL, 0);
        for(int a=0;a<3;a++)
        {
            printf("Reading %d:\n", a+1);
            for (int i = 0; i < 20; i++)
            {
              printf("%c",shm[i]);
            }
            printf("\n");
            sem_wait(sem);
        }
        shmdt(shm);
        sem_close(sem);
        sem_unlink(SEM_NAME);
    }
  }

   
