#include<stdio.h>
#include<pthread.h>
#define SIZE 5
int array[SIZE];

void* input_array(void* arg){
printf("Enter %d integets.\n", SIZE);
for(int i = 0; i < SIZE; i++){
printf("Enter %d integer value.\n", i+1);
scanf("%d",&array[i]);
}
pthread_exit(NULL);
}

void* calculate_average(void* arg){
	int sum = 0;
	for(int i = 0; i < SIZE; i++){
		sum = sum + array[i];
	}
	float average = (float)sum/SIZE;
	printf("Average = %.2f\n", average);
	pthread_exit(NULL);
}

int main(){
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, input_array, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2,NULL, calculate_average,NULL);
	pthread_join(t2, NULL);

	return 0;
}


