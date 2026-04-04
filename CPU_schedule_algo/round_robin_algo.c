//Round Robin algorithm
# include <stdio.h>
# define SIZE 100
struct Process{
char name[10];
int arrival;
int burst;
int ct, wt, tat;
int remaining;
};
//circular queue / ready queue
int queue[SIZE];
int front = -1;
int rear = -1;

//check queue is full or not
int isFull(int n){
if((rear + 1)%n == front){
return 1;
}else{
return 0;
}
};
//check queue is empty or not
int isEmpty(){
if(front == -1){
return 1;
}else{
return 0;
}
}

//enqueue
void enqueue(int value, int n){
if(isFull(n)){
printf("Queue is full\n");
return;
}else{
if(front == -1){
front = 0;
}
rear = (rear + 1)%n;
queue[rear] = value;
printf("The inserted value is %d\n", value);

};
};

//dequeue
int dequeue(int n){
int value;
if(isEmpty()){
printf("The queue is empty\n");
return -1;
}else{
value = queue[front];
//printf("The deleted value is %d\n", queue[front]);
if(front == rear){
front = -1;
rear = -1;
}else{
front = (front +1) %n;
};
};
return value;
};

int main(){
int completed = 0;
int quantum;
int time = 0;
int n;
printf("Enter the number of processes: \n");
scanf("%d", &n);
struct Process p[n];

//Enter the details of the processes
printf("Enter the details of the process(s). Ex.- Process Name, Arrival time, Burst time\n");
for(int i = 0; i < n; i++){
printf("Details of %d process: \n", i);
scanf("%s %d %d", p[i].name, &p[i].arrival, &p[i].burst);
p[i].remaining =  p[i].burst;

}
printf("Enter the value of slice time: \n");
scanf("%d", &quantum);

//Process solving conditions
//Initially enqueue processes that arive at time 0
for (int i = 0 ; i < n; i++){
if(p[i].arrival == 0){
enqueue(i, n);
}
}
while(completed < n){
if(isEmpty()){
time ++; //if no process is in queue, CPU waits
continue;
}
int i = dequeue(n);
if(p[i].remaining > quantum){
time =  time + quantum;
p[i].remaining = p[i].remaining - quantum;
}else{
time = time + p[i].remaining;
p[i].remaining = 0;
p[i].ct = time;
completed ++;
}

//Add newly arrived processes
for(int j = 0; j< n; j++){
if(p[j].arrival <= time && p[j].remaining > 0){
int alreadyInqueue = 0;
if(!isEmpty()){
for(int k = front; ; k = (k + 1)%n){
if(queue[k] == j){
alreadyInqueue = 1;
break;
}

if(k == rear)
break;
}
}
if(!alreadyInqueue && j != i){
enqueue(j, n);
}
}
}
//Of process still remaining, enqueue again
if(p[i].remaining > 0)
enqueue(i, n);
}

int total_tat = 0;
int total_wt = 0;
for (int i = 0; i < n; i++){
p[i].tat = p[i].ct - p[i].arrival;
p[i].wt = p[i].tat - p[i].burst;

total_tat = total_tat + p[i].tat;
total_wt = total_wt + p[i].wt;
}

//Display the result
float avg_tat = 0;
float avg_wt = 0;
printf("=============Solutions=================\n");
printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "Process", "Arrival", "Burst", "Completion", "TurnAround", "Waiting");
for(int i = 0; i < n; i++){
printf("%-10s %-10d %-10d %-10d %-10d %-10d\n", p[i].name, p[i].arrival, p[i].burst, p[i].ct, p[i].tat, p[i].wt);
}
avg_tat = (float)total_tat/n;
avg_wt = (float)total_wt/n;
printf("The average turnaround time: %.2f\n", avg_tat);
printf("The average waiting time: %.2f\n", avg_wt); 

return 0;
}
