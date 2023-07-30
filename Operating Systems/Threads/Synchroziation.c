#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>


struct node
{
    int data;
    struct node* next;
};

struct queue
{
    struct node* head;
    int size;
};


void init_queue(struct queue* q)
{
    q->size = 0;
    q->head = NULL;
}

void enqueue(struct queue* q, int x)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node)); // use malloc to allocate memory for new node
    temp->data = x;
    temp->next = NULL;
    if (q->head == NULL)
    {
        q->head = temp;
    }
    else
    {
        struct node* current = q->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
    q->size++;
}

int seek(struct queue* q)
{
    return q->head->data;
}

void dequeue(struct queue* q)
{
    if (q->size > 0)
    {
        q->head = q->head->next;
        q->size--;
    }
    else
    {
        printf("already empty \n");
    }
}

struct queue obj;
int n;
bool flag = false;

void *worker_thread1(void *arg)
{
    FILE *f1;
    f1 = fopen("data.txt", "r");
    if (f1 == NULL)
    {
        printf("error\n");
    }
    while (fscanf(f1, "%d", &n) != EOF)
    {
    }
    flag = true;
    fclose(f1); 
}

void *worker_thread2(void *arg)
{
    while (flag == false)
    {
        enqueue(&obj, n); 
    }
}

void print_data()
{
    while (obj.size != 0)
    {
        printf("%d \n", seek(&obj)); 
        dequeue(&obj); 
    }
}

int main()
{
    init_queue(&obj);
    pthread_t my_thread1;
    pthread_t my_thread2;
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
    pthread_join(my_thread1, NULL); // wait for thread 1 to complete
    pthread_join(my_thread2, NULL); // wait for thread 2 to complete
    print_data();
    pthread_exit(NULL);
}
