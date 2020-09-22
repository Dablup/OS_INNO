#include <stdio.h>
struct process{
 int arrivalTime;
 int burstTime; 
 int numberOfProcess;
 int completionTime;
 int waitingTime;
 int turnAroundTime;
};

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

int main(void) {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
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
  for (int i = 0; i < n; i++){
    printf("%d process ------ arrival time = %d ------- burst time = %d\n",process_list[i].numberOfProcess,process_list[i].arrivalTime,process_list[i].burstTime);
  }
  printf("\n");

  for (int i = 0; i < n; i++){
    if (i == 0){
      process_list[i].waitingTime = 0;
      process_list[i].completionTime = process_list[i].waitingTime + process_list[i].burstTime;
      process_list[i].turnAroundTime = process_list[i].burstTime + process_list[i].waitingTime;
    } else{
      process_list[i].waitingTime = process_list[i-1].completionTime - process_list[i].arrivalTime;
      if (process_list[i].waitingTime < 0){
        process_list[i].waitingTime = 0;
        process_list[i].completionTime = process_list[i].burstTime + process_list[i-1].completionTime + (process_list[i].arrivalTime - process_list[i-1].completionTime); 
        process_list[i].turnAroundTime = process_list[i].burstTime + process_list[i].waitingTime;
      } else {
        process_list[i].completionTime =  process_list[i].burstTime + process_list[i-1].completionTime;
        process_list[i].turnAroundTime = process_list[i].burstTime + process_list[i].waitingTime; 
      }
      
    }
  }
  for (int i = 0; i < n; i++){
       printf("For the %d process -- completion time = %d -- turn around time = %d -- waiting time = %d \n",process_list[i].numberOfProcess,process_list[i].completionTime,process_list[i].turnAroundTime,process_list[i].waitingTime);
  }

  printf("\n");
  float sum_of_turnAround=0;
  float sum_of_Waiting=0;
  for (int i = 0; i < n;i++){
    sum_of_Waiting = sum_of_Waiting + process_list[i].waitingTime;
    sum_of_turnAround = sum_of_turnAround + process_list[i].turnAroundTime;
  }
  printf("Average turnaround time is %f\n",sum_of_turnAround/n);
  printf("Average waiting time is %f\n",sum_of_Waiting/n);
  return 0;
}
