#include<stdio.h>
#include<pthread.h>
#define SIZE 5

int arr[SIZE];
int data_ready = 0;
pthread_mutex_t lock;

void* input_array(void* arg){
	pthread_mutex_lock(&lock);
	for(int i = 0; i < SIZE; i++){
		printf("Enter %d integer: \n", i+1);
		scanf("%d", &arr[i]);
		
	}
	data_ready = 1;
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}



void* calculate_average(void* arg){
	while(1){
		pthread_mutex_lock(&lock);
		if(data_ready == 1){
			int sum = 0;
			for(int i = 0; i < SIZE; i++){
				sum = sum + arr[i];
			}
			float average = (float)sum/SIZE;
			printf("Average: %.2f\n", average);
			pthread_mutex_unlock(&lock);
			break;
		}
		pthread_mutex_lock(&lock);
		pthread_exit(NULL);
	}

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



		
