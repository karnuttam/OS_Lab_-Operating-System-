#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* myThread(void* arg){
	int num = *(int*)arg;

	int* result = malloc(sizeof(int));
	*result = num * num;
	return result;
}
int main(){
	pthread_t t;
	int num;
	printf("Enter the number: ");
	scanf("%d", &num);
	void* res;
	pthread_create(&t, NULL, myThread, &num);
	pthread_join(t, &res);

	printf("Square = %d\n", *(int*)res);
	free(res);
	return 0;
}

