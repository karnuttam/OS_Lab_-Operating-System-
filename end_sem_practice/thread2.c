#include<stdio.h>
#include<pthread.h>

void* printMessage(void* arg){
	printf("Thread ID: %ld\n", pthread_self());
}
int main(){
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, printMessage, NULL);
	pthread_create(&t2, NULL, printMessage, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}
