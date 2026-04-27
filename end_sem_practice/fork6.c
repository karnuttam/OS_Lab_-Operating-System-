#include<stdio.h>
#include<unistd.h>

int main(){
	int a = 5, b = 10;
	pid_t pid = fork();
	if (pid == 0){
		a = a+2;
	}else{
		b = b + 2;
	}
	if(pid == 0){
		a = a +3;
	}else{
		b = b +3;
	}
	printf("PID: %d | a = %d, b = %d\n", getpid(), a, b);
	return 0;
}
