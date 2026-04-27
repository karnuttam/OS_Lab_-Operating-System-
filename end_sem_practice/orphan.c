#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid = fork();
	if (pid >  0){
		printf("Parent process exiting.\n");
		printf("Parent Process ID: %d\n", getpid());
	}else{
		sleep(10);
		printf("Child Process");
		printf("PID: %d, Parent PID: %d\n", getpid(), getppid());
	}
	return 0;
}
