#include<stdio.h>
#include<pthread.h>

void* printNumber(void* arg){
	int num = *(int*)arg;
	printf("Number = %d\n", num);
	return NULL;
}
int main(){
	pthread_t t;
	int value = 10;

	pthread_create(&t, NULL, printNumber, &value);
	pthread_join(t, NULL);
	return 0;
}
