# include<pthread.h>
# include<stdio.h>
void* myThread(void* arg){
printf("Hello from the new thread\n");
return NULL;
}
int main(){
pthread_t thread1;
//Creating a new thread
pthread_create(&thread1, NULL, myThread, NULL);
//Waiting for the thread to finish
pthread_join(thread1, NULL);
printf("Main thread finished\n");
return 0;
}
