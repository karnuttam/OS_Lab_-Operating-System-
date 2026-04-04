//First come first serve algorithm 
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
//Arrival time is not sorted
for(int i = 0; i < n-1; i++){
for(int j = 0; j < n - 1 - i; j++){
if(p[j].arrival > p[j + 1].arrival){
struct Process temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;
}
}
}
//calculation
//Assuming processes are sorted by arrival time
int total_tat = 0;
int total_wt = 0;
for(int i = 0; i < n; i++){
if(time < p[i].arrival){
time = p[i].arrival;
p[i].ct = time + p[i].burst;
}else{
p[i].ct = time + p[i].burst;
}
time = p[i].ct;
p[i].tat = p[i].ct - p[i].arrival;
p[i].wt = p[i].tat - p[i].burst;
total_tat = total_tat + p[i].tat;
total_wt = total_wt + p[i].wt;
}
//Display the result;
float avg_tat = 0;
float avg_wt = 0;
printf("The result of the Processes are following: \n");
printf("%-10s %-10s %-10s %-10s %-12s %-10s\n","Process", "Arrival", "Burst", "Comp_Time", "Turnaround_t", "Waiting_time");
for(int i = 0; i < n; i++){
printf("%-10s %-10d %-10d %-10d %-12d %-10d \n", p[i].name, p[i].arrival, p[i].burst, p[i].ct, p[i].tat, p[i].wt );
}
avg_tat = total_tat/n;
avg_wt = total_wt/n;
printf("The average turnaround time: %.2f\n", avg_tat);
printf("The average waiting time: %.2f\n", avg_wt);
return 0;
}
