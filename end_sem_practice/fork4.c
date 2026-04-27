#include<stdio.h>
#include<unistd.h>

int main(){
	int x = 10;
	pid_t pid = fork();
	if (pid == 0){
		x = x + 10;
		printf("The value of x is %d\n", x);
		printf("The Child Process PID: %d\n", getpid());
	}else{
		x = x -5;
		printf("The value of x is %d\n", x);
		printf("The Parent Process PID: %d\n", getpid());
	}
	return 0;
}
