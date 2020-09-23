#include <stdio.h>
struct process{
    int arrivalTime;
    int burstTime;
    int numberOfProcess;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
};

void findAllMetrics(struct process process_list[], int n, int quantum){
    // Сreate a copy of burst times to delete them during the algorithm.
    int copy_of_burst[n];
    for (int i = 0 ; i < n ; i++)
        copy_of_burst[i] =  process_list[i].burstTime;

    //total time to finish all the processes
    int total_time = 0;
    //Traversing all the processes until all of them are done
    while (1){
        int done = 1;
        for (int i = 0 ; i < n; i++){
            // If burst time of a process is greater than 0 than just proceed
            if (copy_of_burst[i] > 0){
                done = 0;
                if (copy_of_burst[i] > quantum){
                    // Increase the value of total time by quantum
                    total_time += quantum;
                    // Decrease the burst_time of current process by quantum
                    copy_of_burst[i] -= quantum;
                }
                    // If burst time is smaller than or equal to quantum then it means that it is  the last cycle for this process
                else{
                    total_time = total_time + copy_of_burst[i];
                    // As the process gets fully executed make its remaining burst time = 0 and find all the metrics
                    copy_of_burst[i] = 0;
                    process_list[i].completionTime = total_time;
                    process_list[i].waitingTime = process_list[i].completionTime - process_list[i].burstTime - process_list[i].arrivalTime;
                    process_list[i].turnAroundTime = process_list[i].burstTime + process_list[i].waitingTime;
                    printf("process %d -- arrival time %d -- burst time %d -- completion time %d -- waiting time %d -- turnaround time %d \n",process_list[i].numberOfProcess, process_list[i].arrivalTime,process_list[i].burstTime,process_list[i].completionTime,process_list[i].waitingTime,process_list[i].turnAroundTime);
                }
            }
        }

        // If all processes are done
        if (done == 1)
            break;
    }
}


void findAndOutputEverything(struct process process_list[], int n,int quantum){

    // Function to find metrics of all processes
    findAllMetrics(process_list, n, quantum);

    // Calculate total waiting time and total turn around time
    int  total_waiting_time = 0;
    int  total_tat_time = 0;
    for (int i=0; i<n; i++){
        total_waiting_time = total_waiting_time + process_list[i].waitingTime;
        total_tat_time = total_tat_time + process_list[i].turnAroundTime;
    }
    printf("Average waiting time = %f\n", (float)total_waiting_time / (float)n);
    printf("Average turnaround time = %f\n", (float)total_tat_time / (float)n);
}


int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\n");
    struct process process_list[n];
    for (int i = 0; i<n;i++){
        printf("Enter the arrival time and burst time of the process %d: ",i+1);
        scanf("%d%d",&process_list[i].arrivalTime,&process_list[i].burstTime);
        process_list[i].numberOfProcess = i+1;
        printf("\n");
    }
    printf("\n");
    int quantum;
    printf("Enter the value of quantum: ");
    scanf("%d",&quantum);
    printf("\n");
    findAndOutputEverything(process_list, n, quantum);
    return 0;
}
