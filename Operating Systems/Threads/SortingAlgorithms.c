#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
void selectionsort(int arr[], int n) 
{ 
    int x, y, min; 
    for(x=0;x<n-1;x++) 
    { 
        min=x; 
        for(y=x+1;y<n;y++)
		{ 
            if (arr[y] < arr[min]) 
            {
                min=y;
			}
		}
        int temp=arr[min]; 
        arr[min]=arr[x]; 
        arr[x]=temp; 
    } 
} 

void sort4()
{
	FILE *f11;
	f11 = fopen("numbers4.txt", "r");
	if (f11 == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	int arr[250000];
	int n;
	int count = 0;
	while (fscanf(f11, "%d", &n) == 1 && count < 250000)
	{
		arr[count] = n;
		count++;
	}
	fclose(f11);
	selectionsort(arr, 250000);
	FILE *f12;
	f12 = fopen("sorted4.txt", "w");
	if (f12 == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	for(int a=0;a<count;a++)
	{
		fprintf(f12, "%d\n", arr[a]);
	}	
	fclose(f12);
}
void insertionsort(int arr[], int n) 
{ 
    int x, y, tmp; 
    for (x = 1; x < n; x++) 
	{ 
        tmp = arr[x]; 
        y=x-1; 
        while (y >= 0 && arr[y] > tmp)
		{ 
            arr[y+1]=arr[y]; 
            y=y-1; 
        } 
        arr[y+1]=tmp; 
    } 
} 
void sort3()
{
	FILE *f9;
	f9 = fopen("numbers3.txt", "r");
	if (f9 == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	int arr[250000];
	int n;
	int count = 0;
	while (fscanf(f9, "%d", &n) == 1 && count < 250000)
	{
		arr[count] = n;
		count++;
	}
	fclose(f9);
	insertionsort(arr, 250000);
	FILE *f10;
	f10 = fopen("sorted3.txt", "w");
	if (f10 == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	for(int a=0;a<count;a++)
	{
		fprintf(f10, "%d\n", arr[a]);
	}	
	fclose(f10);
}
void quicksorting(int arr[],int x1,int x2)
{
   int i, j, pivot, temp;
   if(x1<x2)
   {
      pivot=x1;
      i=x1;
      j=x2;

      while(i<j)
	  {
        while(arr[i]<=arr[pivot]&&i<x2)
        {
            i++;
        }
        while(arr[j]>arr[pivot])
        {
            j--;
        }
        if(i<j)
		{
	        temp=arr[i];
	        arr[i]=arr[j];
	        arr[j]=temp;
        }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksorting(arr,x1,j-1);
      quicksorting(arr,j+1,x2);

   }
}
void sort2()
{
	FILE *f7;
	f7 = fopen("numbers2.txt", "r");
	int arr[250000];
	int n;
	for(int a=0;a<250000;a++)
	{
		fscanf(f7, "%d", &n);
		arr[a]=n;
	}
	quicksorting(arr,0,249999);
	fclose(f7);
	FILE *f8;
	f8 = fopen("sorted2.txt", "w");
	for(int a=0;a<250000;a++)
	{
		fprintf(f8, "%d\n", arr[a]);
	}	
}
void main_merge(int arr[], int l[], int ls, int r[], int rs) 
{
    int i = 0, j = 0, k = 0;
    while (i < ls && j < rs)
	 {
        if (l[i] <= r[j]) 
		{
            arr[k++] = l[i++];
		} 
		else 
		{
            arr[k++] = r[j++];
        }
    }
    while (i < ls) 
	{
        arr[k++] = l[i++];
    }
    while (j < rs)
	{
        arr[k++] = r[j++];
    }
}
void mergesort(int arr[], int size) 
{
    if (size <= 1) 
	{
        return;
    }
    int mid = size / 2;
    int *l = (int*)malloc(mid * sizeof(int));
    int *r = (int*)malloc((size - mid) * sizeof(int));
    for (int i = 0; i < mid; i++)
	{
        l[i] = arr[i];
    }
    for (int i = mid; i < size; i++) 
	{
        r[i - mid] = arr[i];
    }
    mergesort(l, mid);
    mergesort(r, size - mid);
    main_merge(arr, l, mid, r, size - mid);
    free(l);
    free(r);
}

void sort1()
{
	FILE *f5;
	f5 = fopen("numbers1.txt", "r");
	int arr[250000];
	int n;
	for(int a=0;a<250000;a++)
	{
		fscanf(f5, "%d", &n);
		arr[a]=n;
	}
	mergesort(arr,250000);
	fclose(f5);

	FILE *f6;
	f6 = fopen("sorted1.txt", "w");
	for(int a=0;a<250000;a++)
	{
		fprintf(f6, "%d\n", arr[a]);
	}	
}
void printtime()
{
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    char time_str[9];
    strftime(time_str, sizeof(time_str), "%H:%M:%S", local_time);
    printf(" Current time: %s ", time_str);
}

void *worker_thread1(void *arg)
{
    printf("  merge SORT BEGINS at following time \n ");
    printtime();
    printf("  Thread ID: %ld \n", pthread_self());
    sort1();
    printf("  merge SORT EXITS at following time \n");
    printtime();
    printf("\n");
}
void *worker_thread2(void *arg)
{
    printf("  quick SORT BEGINS at following time  \n");
    printtime();
    printf("  Thread ID: %ld \n", pthread_self());
    sort2();
    printf("  quick SORT EXITS at following time \n");
    printtime();
    printf("\n");
}
void *worker_thread3(void *arg)
{
    printf("  insertion SORT BEGINS at following time \n ");
    printtime();
    printf("  Thread ID: %ld \n", pthread_self());
    sort3();
    printf("  insertion SORT EXITS at following time \n");
    printtime();
    printf("\n");
}
void *worker_thread4(void *arg)
{
    printf("  selection SORT BEGINS at following time \n ");
    printtime();
    printf("  Thread ID: %ld \n", pthread_self());
    sort4();
    printf("  selection SORT EXITS at following time \n ");
    printtime();
    printf("\n");
}
int main()
{
	FILE *f1;
	FILE *f2;
	FILE *f3;
	FILE *f4;
	f1 = fopen("numbers1.txt", "w");
	f2 = fopen("numbers2.txt", "w");
	f3 = fopen("numbers3.txt", "w");
	f4 = fopen("numbers4.txt", "w");
	srand(time(NULL));
	int x;
	for(int a=0;a<250000;a++)
	{
		x = rand();
    	fprintf(f1, "%d\n", x);
	}
	for(int a=0;a<250000;a++)
	{
		 x = rand();
    	fprintf(f2, "%d\n", x);
	}
	for(int a=0;a<250000;a++)
	{
		 x = rand();
    	fprintf(f3, "%d\n", x);
	}
	for(int a=0;a<250000;a++)
	{
		 x = rand();
    	fprintf(f4, "%d\n", x);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
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
        pthread_join(my_thread1, NULL); // wait for thread 1 to complete
        pthread_join(my_thread2, NULL); // wait for thread 2 to complete
        pthread_join(my_thread3, NULL); // wait for thread 3 to complete
        pthread_join(my_thread4, NULL); // wait for thread 4 to complete
        FILE *f21;
	FILE *f22;
	FILE *f23;
	FILE *f24;
	FILE *f25;
	f21 = fopen("sorted1.txt", "r");
	f22 = fopen("sorted2.txt", "r");
	f23 = fopen("sorted3.txt", "r");
	f24 = fopen("sorted4.txt", "r");
	f25 = fopen("output.txt","w");
	int ax;
	for(int a=0;a<250000;a++)
	{
		fscanf(f21, "%d", &ax);
		fprintf(f25, "%d\n", ax);
	}
	for(int a=0;a<250000;a++)
	{
		fscanf(f22, "%d", &ax);
		fprintf(f25, "%d\n", ax);
	}
	for(int a=0;a<250000;a++)
	{
		fscanf(f23, "%d", &ax);
		fprintf(f25, "%d\n", ax);
	}
	for(int a=0;a<250000;a++)
	{
		fscanf(f24, "%d", &ax);
		fprintf(f25, "%d\n", ax);
	}
	pthread_exit(NULL);
}