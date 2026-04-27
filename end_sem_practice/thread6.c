#include<stdio.h>
#include<pthread.h>

void* printMessage(void* arg){
	char* message = (char*)arg;
	printf("Thread says: %s\n",message);
	pthread_exit(NULL);
}

int main(){
	pthread_t t1;
	pthread_t t2;
	char str1[20];
	char str2[20];
	printf("Enter the first string: \n");
	fgets(str1, sizeof(str1), stdin);
	printf("Enter the second string: \n");
	fgets(str2, sizeof(str2), stdin);

	pthread_create(&t1, NULL, printMessage, &str1);
	pthread_create(&t2, NULL, printMessage, &str2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}
