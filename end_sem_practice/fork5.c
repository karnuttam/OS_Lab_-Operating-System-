#include<stdio.h>
#include<unistd.h>

int main(){
	int a= 5, b=10;
	fork();
	a = a + 1;
	fork();
	b = b + 2;
	printf("PID: %d | a = %d, b = %d\n", getpid(), a, b);
	return 0;
}
