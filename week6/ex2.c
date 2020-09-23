#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct process{
    int arrivalTime;
    int burstTime;
    int numberOfProcess;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
};

// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* create_Queue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
            sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
            queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    //printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeu(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}


void process_compare(struct process* a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j].arrivalTime > a[j+1].arrivalTime)
            {
                struct process tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1]=tmp;
            }
        }
    }
}

void process_compare_for_AT0(struct process* a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j].burstTime> a[j+1].burstTime)
            {
                struct process tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1]=tmp;
            }
        }
    }
}

int main(void) {

    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct queue* q = create_Queue(n);
    enqueue(q,0);
    int used_procesese[n];
    struct process process_list[n];
    for (int i = 0; i<n;i++){
        printf("Enter the arrival time and burst time of the process %d: ",i+1);
        scanf("%d%d",&process_list[i].arrivalTime,&process_list[i].burstTime);
        process_list[i].numberOfProcess = i+1;
    }
    process_compare(process_list,n);
    printf("\n");
    printf("The order in which processes will be executed: \n");
    printf("\n");
    process_list[0].completionTime = process_list[0].arrivalTime + process_list[0].burstTime;
    process_list[0].waitingTime = 0;
    process_list[0].turnAroundTime = process_list[0].completionTime;
    int checkAT = 0;
    for (int i =0; i < n; i++){
        checkAT = checkAT + process_list[i].arrivalTime;
    }
    if (checkAT == 0){
        process_compare_for_AT0(process_list,n);
        process_list[0].completionTime = process_list[0].arrivalTime + process_list[0].burstTime;
        process_list[0].waitingTime = 0;
        process_list[0].turnAroundTime = process_list[0].completionTime;
        for (int i = 0; i < n; i++){
            if (i != 0){
            process_list[i].completionTime = process_list[i-1].completionTime + process_list[i].burstTime;
            process_list[i].waitingTime = process_list[i].completionTime - process_list[i].burstTime - process_list[i].arrivalTime;
            process_list[i].turnAroundTime = process_list[i].burstTime + process_list[i].waitingTime;

        }
            printf("process %d -- waiting time %d -- completing time %d -- turn around time %d -- arrival time %d -- burst time %d\n", process_list[i].numberOfProcess, process_list[i].waitingTime, process_list[i].completionTime, process_list[i].turnAroundTime, process_list[i].arrivalTime, process_list[i].burstTime);
        }
    }else {
        while(!isEmpty(q)){
            int num_of_top_process = dequeu(q);
            struct process current = process_list[num_of_top_process];
            printf("process %d -- waiting time %d -- completing time %d -- turn around time %d -- arrival time %d -- burst time %d\n", current.numberOfProcess, current.waitingTime, current.completionTime, current.turnAroundTime, current.arrivalTime, current.burstTime);
            used_procesese[num_of_top_process] = 1;
            int min_value_of_burstTime = INT_MAX;
            int numberOfMin = -1;
            for (int i = 0; i<n;i++){
                if(used_procesese[i] != 1 && current.completionTime > process_list[i].arrivalTime && process_list[i].burstTime < min_value_of_burstTime){
                    min_value_of_burstTime = process_list[i].burstTime;
                    numberOfMin = i;
                }
            }
            if (numberOfMin == -1) break;
            process_list[numberOfMin].completionTime = current.completionTime + min_value_of_burstTime;
            process_list[numberOfMin].waitingTime = process_list[numberOfMin].completionTime - process_list[numberOfMin].burstTime - process_list[numberOfMin].arrivalTime;
            process_list[numberOfMin].turnAroundTime = min_value_of_burstTime + process_list[numberOfMin].waitingTime;

            enqueue(q,numberOfMin);
        }
    }
    return 0;
}
