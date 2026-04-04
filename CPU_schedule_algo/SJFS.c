//Sortest Job First Scheduling
//Declare a structure Process having members name[10], burstTime, arrivalTime, ct, wt and tat with appropriate data types. Take user input for 5 processes and calculate AWT and ATAT using the FCFS CPU Scheduling Algorithm.

# include <stdio.h>
struct Process{
char name[10];
int arrival;
int burst;
int ct, tat, wt;
};
int main(){
int n; int time = 0;
//Details of Process
printf("Enter the number of processes you want to calculate: \n");
scanf("%d", &n);
struct Process p[n];
for(int i = 0 ; i < n; i++){
printf("Enter the %d process( Process Name, Arrival time, burst time): \n", i);
scanf("%s %d %d", p[i].name, &p[i].arrival, &p[i].burst); 
}

//calculation
//Assuming processes are sorted by arrival time
int total_tat = 0;
int total_wt = 0;

int completed = 0;
int visited[n];
for(int i = 0; i < n; i++){
visited[i] = 0;

}
while(completed < n){
int min_index = -1;
int min_burst = 9999;
  //find process with minimum burst among arrived processes
  for (int i = 0; i < n; i++){
  if(p[i].arrival <= time && visited[i] == 0){
  if(p[i].burst < min_burst){
  min_burst = p[i].burst;
  min_index = i;
  }
  }
  }
  // if no process has arrived yet
  if(min_index == -1){
  time ++;
  }else{
  p[min_index].ct = time + p[min_index].burst;
  time = p[min_index].ct;
  p[min_index].tat =  p[min_index].ct - p[min_index].arrival;
  p[min_index].wt = p[min_index].tat - p[min_index].burst;
  
  total_tat = total_tat + p[min_index].tat;
  total_wt = total_wt + p[min_index].wt;
  visited[min_index] = 1;
  completed++;
  }
}
//Display the result;
float avg_tat = 0;
float avg_wt = 0;
printf("The result of the Processes are following: \n");
printf("%-10s %-10s %-10s %-10s %-12s %-10s\n","Process", "Arrival", "Burst", "Comp_Time", "Turnaround_t", "Waiting_time");
for(int i = 0; i < n; i++){
printf("%-10s %-10d %-10d %-10d %-12d %-10d \n", p[i].name, p[i].arrival, p[i].burst, p[i].ct, p[i].tat, p[i].wt );
}
avg_tat = (float)total_tat/n;
avg_wt = (float)total_wt/n;
printf("The average turnaround time: %.2f\n", avg_tat);
printf("The average waiting time: %.2f\n", avg_wt);
return 0;
}
