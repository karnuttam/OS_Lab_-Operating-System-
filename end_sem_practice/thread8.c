#include<stdio.h>
#include<pthread.h>

//Function for addition
void* addition(void* arg){
	int a, b;
	printf("Enter the value of a: \n");
	scanf("%d", &a);
	printf("Enter the value of b: \n");
	scanf("%d",&b);

	int sum = 0;
	sum = (a + b);
	printf("Addition: %d\n", sum);

	pthread_exit(NULL);
}

void* subtraction(void* arg){
	int a, b;
	printf("Enter the value of a: \n");
	scanf("%d", &a);
	printf("Enter the value of b: \n");
	scanf("%d", &b);
	int sub;
	sub = (a - b);
	printf("Subtraction: %d\n", sub);
	pthread_exit(NULL);
}

void* multiplication(void* arg){
	int a,b;
	printf("Enter the value of a: \n");
	scanf("%d",&a);
	printf("Enter the value of b: \n");
	scanf("%d",&b);
	int multiply;
	multiply = (a * b);
	printf("Multiplication: %d\n", multiply);
	pthread_exit(NULL);
}


void* division(void* arg){
	float a, b;
	printf("Enter the value of a: \n");
	scanf("%f", &a);
	printf("Enter the value of b: \n");
	scanf("%f", &b);
	if(b == 0){
		printf("Undefined!\n");
		return 0;
	}else{
		float division = (a/b);
		printf("Division: %.2f\n", division);
	}
	pthread_exit(NULL);
}

int main(){
pthread_t t1, t2, t3, t4;
pthread_create(&t1, NULL, addition,NULL);
pthread_join(t1, NULL);
pthread_create(&t2, NULL, subtraction, NULL);
pthread_join(t2, NULL);
pthread_create(&t3, NULL, multiplication, NULL);
pthread_join(t3, NULL);
pthread_create(&t4, NULL, division, NULL);
pthread_join(t4, NULL);
return 0;
}
