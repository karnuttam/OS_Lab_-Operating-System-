# include <stdio.h>
# include <pthread.h>
void* print_message(void* arg){
printf("Thread says: %s\n", (char*)arg);
pthread_exit(NULL);
}
int main(){
pthread_t t1, t2;

pthread_create(&t1, NULL, print_message, "Hello");
pthread_create(&t2, NULL, print_message, "World");

pthread_join(t1, NULL);
pthread_join(t2, NULL);
return 0;
}
