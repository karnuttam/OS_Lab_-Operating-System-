# include <stdio.h>
# include <pthread.h>
#define SIZE 5
int arr[SIZE];
int data_ready = 0;

pthread_mutex_t lock;
//Thread1: Takes input
void* input_array(void* arg){
pthread_mutex_lock(&lock);

printf("Enter %d integers: \n", SIZE);
for(int i = 0; i <SIZE; i++){
scanf("%d", &arr[i]);
}
data_ready = 1;//indicates data is ready
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}
//Thread 2: Calculate average
void* calculate_average(void* arg){
while(1){
pthread_mutex_lock(&lock);

if(data_ready == 1){
int sum = 0;
for(int i = 0; i < SIZE; i++){
sum += arr[i];
}
float avg = (float)sum/SIZE;
printf("Average = %.2f\n", avg);
pthread_mutex_unlock(&lock);
break;
}
pthread_mutex_unlock(&lock);
}
pthread_exit(NULL);
}
int main(){
pthread_t t1, t2;
pthread_mutex_init(&lock, NULL);
pthread_create(&t1, NULL, input_array, NULL);
pthread_create(&t2, NULL, calculate_average, NULL);

pthread_join(t1, NULL);
pthread_join(t2, NULL);
pthread_mutex_destroy(&lock);
return 0;
}
