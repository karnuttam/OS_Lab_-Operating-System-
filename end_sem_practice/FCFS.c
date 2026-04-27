#include<stdio.h>

struct Process{
	char name[20];
	int arrival_time;
	int completion_time;
	int burst_time;
	int turnaround_time;
	int waiting_time;
};

int main(){
	printf("==============First Come First Serve Algorithm FIFO)========\n");
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
	}
	//sorting by arrival time
	for(int i = 0; i < n - 1; i++){
	for(int j = 0; j < n - i - 1; j++){
	if(p[j].arrival_time > p[j+1].arrival_time){
	struct Process temp = p[j];
	p[j] = p[j+1];
	p[j+1] = temp;
	}
	}
	}
	
	
	int total_tat = 0;
	int total_wt = 0;
	//FCFS Logic
	int current_time = 0;
	for(int i = 0; i < n; i++){
	if (current_time < p[i].arrival_time){
	current_time = p[i].arrival_time;
	}else{
	//CPU continues, no idle time
	}
	
	p[i].completion_time = current_time + p[i].burst_time;
	
	p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
	
	p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
	
	current_time = p[i].completion_time;
	
	total_tat = total_tat+p[i].turnaround_time;
	total_wt = total_wt+ p[i].waiting_time;
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

	


