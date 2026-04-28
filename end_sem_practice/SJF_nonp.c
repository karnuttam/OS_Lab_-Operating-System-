#include<stdio.h>

struct Process{
	char name[20];
	int arrival_time;
	int completion_time;
	int burst_time;
	int turnaround_time;
	int waiting_time;
	int completed;
	
};

int main(){
	printf("==============Shortest Job First Algorithm (SJF)========\n");
	int n;
	printf("Enter the total number of processes: \n");
	scanf("%d", &n);
	struct Process p[n];
	for(int i = 0; i < n; i++){
		printf("Enter the name of %d process\n", i+1);
		scanf("%s", p[i].name);
		printf("Arrival Time: \n");
		scanf("%d", &p[i].arrival_time);
		printf("Burst Time: \n");
		scanf("%d", &p[i].burst_time);
		p[i].completed = 0;
	}
	//SJF Logic
	int current_time = 0;
	int completed_count = 0;
	int total_tat = 0;
	int total_wt = 0;
	while(completed_count < n){
	int idx = -1;
	int min_bt = 100000;
	for(int i = 0; i < n; i++){
	
	if(p[i].arrival_time <= current_time && p[i].completed == 0){
	
	if(idx == -1){
	idx = i;
	min_bt = p[i].burst_time;
	}else{
	if(p[i].burst_time < min_bt){
	min_bt = p[i].burst_time;
	idx = i;
	}else{
	//do nothing
	}
	}
	}else{
	//Process not eligible
	
	}
	}
	if(idx != -1){
	p[idx].completion_time = current_time + p[idx].burst_time;
	p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
	p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
	p[idx].completed = 1;
	completed_count++;
	current_time = p[idx].completion_time;
	total_tat = total_tat + p[idx].turnaround_time;
	total_wt = total_wt + p[idx].waiting_time;
	}else{
	//CPU is idle;
	current_time = current_time + 1;
	}
	}
	
	
	//Display the result
	float average_wt;
	float average_tat;
	printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "Process", "Arr_Time", "BurstTime","CT", "TAT", "WT");
	for(int i = 0; i < n ; i++){
		printf("%-10s %-10d %-10d %-10d %-10d %-10d\n", p[i].name, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
	}
	average_tat = (float)total_tat/n;
	average_wt = (float)total_wt/n;
	printf("Average turnaround time: %.2f\n", average_tat);
	printf("Average waiting time: %.2f\n", average_wt);

	return 0;
}

	


