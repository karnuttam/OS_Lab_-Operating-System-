# include <stdio.h>
# include <pthread.h>

//shared variables
int a, b;
//Thread function for addition
void* add(void* arg){
printf("Thread ID %lu: Addition: %d + %d = %d\n",
pthread_self(), a, b, a+b);
return NULL;
}
//Thread function for subtraction
void* subtract(void* arg){
printf("Thread ID %lu: Subraction: %d - %d = %d\n",
pthread_self(), a, b, a - b);
return NULL;
}

//Thread function for multiplication
void* multiply(void* arg){
printf("Thread ID %lu: Multiplication: %d * %d = %d\n",
pthread_self(), a, b, a*b);
return NULL;
}

//Thread function for Division
void* divide(void* arg){
if(b != 0){
printf("Thread ID %lu: Division: %d/%d = %.2f\n",
pthread_self(), a, b, (float)a/b);
}else{
printf("Thread ID %lu: Division: Cannot divide by zero\n",
pthread_self());
return NULL;
}
}
int main(){

pthread_t t1, t2, t3, t4;
printf("Enter the first integer: \n");
scanf("%d", &a);
printf("Enter the second integer(b): \n");
scanf("%d", &b);

pthread_create(&t1,NULL,add,NULL);
pthread_create(&t2, NULL, subtract, NULL);
pthread_create(&t3, NULL, multiply, NULL);
pthread_create(&t4, NULL, divide, NULL);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
pthread_join(t3, NULL);
pthread_join(t4, NULL);
return 0;
}
