#include<stdio.h>
#include<unistd.h>

int main(){
	fork();
	printf("Hello from Process!\n");
	return 0;
}
