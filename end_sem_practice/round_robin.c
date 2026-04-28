#include<stdio.h>
struct Process {
char name[20];
int arrival_time;
int burst_time;
int completion_time;
int turnaround_time;
int waiting_time;
int remaining_time;
int completed;
};

int main(){
  printf("====================Round Robin Algorithm================\n");
int n;
printf("Enter the total number of process: \n");
scanf("%d", &n);
int quantum;
printf("Enter the time quantum: \n");
scanf("%d", &quantum);

struct Process p[n];
for(int i = 0; i < n; i++){
printf("Enter the %d process: \n", i+1);
scanf("%s", p[i].name);
printf("Enter the arrival time: \n");
scanf("%d", &p[i].arrival_time);
printf("Enter the burst time: \n");
scanf("%d", &p[i].burst_time);
p[i].remaining_time = p[i].burst_time;
p[i].completed = 0;
}

//Round Robin Logic
int completed_count = 0;
int current_time = 0;
int total_tat = 0;
int total_wt = 0;

while(completed_count < n){
int executed = 0;
for(int i = 0; i < n; i++){
if(p[i].arrival_time <= current_time && p[i].remaining_time > 0){
executed = 1;
if(p[i].remaining_time > quantum){
current_time = current_time + quantum;
p[i].remaining_time = p[i].remaining_time - quantum;
}else{
current_time = current_time + p[i].remaining_time;
p[i].remaining_time = 0;
//completioin time
p[i].completion_time = current_time;

p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
p[i].completed = 1;
completed_count++;
total_tat = total_tat + p[i].turnaround_time;
total_wt = total_wt + p[i].waiting_time; 
}
}
}

if(executed == 0){
current_time ++;
}
}

//Display the result
float average_tat = 0;
float average_wt = 0;
printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "Process", "Arr_time", "Burst_time", "CT", "TAT", "WT");
for(int i = 0; i < n; i++){
printf("%-10s %-10d %-10d %-10d %-10d %-10d\n", p[i].name, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
}
average_tat = (float)total_tat/n;
average_wt = (float)total_wt/n;
printf("Average turnaround time: %.2f\n", average_tat);
printf("Average waiting time: %.2f\n", average_wt);

return 0;
}
