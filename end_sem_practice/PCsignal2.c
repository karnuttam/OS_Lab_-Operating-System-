#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void parent_handler(int sig){
	if(sig == SIGUSR2){
		printf("Parent process received signal from child\n");
	}
}
void child_handler(int sig){
	if(sig == SIGUSR1){
		printf("Child process received the signal.\n");
		kill(getppid(), SIGUSR2);
	}
}

int main(){
	pid_t pid = fork();
	if(pid == 0){
		signal(SIGUSR1, child_handler);
		printf("Child process waiting for signal from parent\n");
		while(1){
			pause();
		}
	}else{
		signal(SIGUSR2, parent_handler);
		sleep(2);
		printf("Parent process sends signal to child.\n");
		kill(pid, SIGUSR1);
		while(1){
			pause();
		}
	}
	return 0;
}
