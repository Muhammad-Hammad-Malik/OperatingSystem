#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int count = 0;
int arr[5] = {5, 25, 45, 65, 85};


struct Node {
    pthread_t thread_id;
    int alarm_num;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void add_to_list(pthread_t thread_id, int alarm_num) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->thread_id = thread_id;
    new_node->alarm_num = alarm_num;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int list_size() {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void *worker_thread1(void *arg)
{
  int x = *((int *) arg);
  time_t start = time(NULL);
  time_t duration = arr[x];
  printf("ALARM NUMBER %d STARTED\n", x);
  while (difftime(time(NULL), start) < duration) {
    // do nothing, wait for alarm to finish
  }
  printf("ALARM NUMBER %d IS AWAKE\n", x);
  int temp = 1;
  char c;
  while(temp==1)
  {
    printf("Would you like to snooze alarm number %d? Enter 'y' for it, or anything else to stop the alarm.\n", x);
    while ((c = getchar()) != '\n' && c != EOF) { } 
    c = getchar(); 
    if(c == 'y')
    {
      printf("Alarm number %d snoozed for 5 seconds\n", x);
      time_t snooze_start = time(NULL);
      while (difftime(time(NULL), snooze_start) < 5) {
        // do nothing, wait for snooze to finish
      }
      printf("ALARM NUMBER %d IS AWAKE\n",x);
    }
    else
    {
      temp=0;
    }
  }
  add_to_list(pthread_self(), x);
}

int main() {
    int n = 5;
    pthread_t my_threads[n];
    for (int a = 0; a < n; a++) {
        int *arg = malloc(sizeof(*arg));
        *arg = a;
        int ret = pthread_create(&my_threads[a], NULL, worker_thread1, arg);
        if (ret != 0) {
            printf("Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }
    while (list_size() < n) {
        // do nothing, just wait for threads to finish
    }
    printf("All alarms have finished\n");
    pthread_exit(NULL);
}
