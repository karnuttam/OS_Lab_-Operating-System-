# include <pthread.h>
# include <stdio.h>

void* myThread(void* arg){
printf("Thread is executing\n");
return NULL;
}
int main(){
pthread_t t1;

//create thread
pthread_create(&t1, NULL, myThread, NULL);
pthread_join(t1, NULL);
printf("Main thread continues after thread finishes\n");
return 0;
}
