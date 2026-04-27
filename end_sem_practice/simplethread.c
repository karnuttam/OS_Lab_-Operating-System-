#include<stdio.h>
#include<pthread.h>

void* myThread(void* arg){
	printf("Hello from thread!\n");
	return NULL;
}

int main(){
	pthread_t t;
	pthread_create(&t, NULL, myThread, NULL);
	pthread_join(t, NULL);
	printf("Main function ends\n");
	return 0;
}
