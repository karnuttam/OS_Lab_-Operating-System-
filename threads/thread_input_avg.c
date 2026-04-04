# include <stdio.h>
# include <pthread.h>
# define SIZE 5
int arr[5];

//Input function
void* input_array(void* arg){
printf("Enter %d integers\n", SIZE);
for(int i = 0; i <SIZE; i++){
scanf("%d", &arr[i]);
}
pthread_exit(NULL);
}
//Calculate average
void* calculate_average(void* arg){
int sum = 0;
for(int i = 0; i < SIZE; i++){
sum += arr[i];

}
float avg = (float)sum/SIZE;
printf("Average = %.2f\n", avg);
pthread_exit(NULL);
}

int main(){
pthread_t t1, t2;
pthread_create(&t1, NULL, input_array, NULL);
//Wait until input thread finishes
pthread_join(t1, NULL);
pthread_create(&t2, NULL,calculate_average, NULL);
pthread_join(t2, NULL);
return 0;
}
