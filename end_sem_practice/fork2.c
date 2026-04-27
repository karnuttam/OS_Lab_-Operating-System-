#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid = fork();
	if (pid == 0){
		printf("Child process is created!\n");
		printf("Child Process PID: %d\n", getpid());
		}
	else{
		printf("Parent Process!\n");
		printf("Parent Process PID: %d\n", getpid());
	}
	return 0;
}
