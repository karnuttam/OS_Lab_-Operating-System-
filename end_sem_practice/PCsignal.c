#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void child_handler(int sig){
	printf("Child received the signal send by Parent Process\n");
}
int main(){
	pid_t pid = fork();
	if(pid == 0){

	signal(SIGUSR1, child_handler);
	while(1){
		pause();
	}
	}
	else{
		sleep(2);
		printf("Parent process sending  signal to Child Process\n");
		kill(pid, SIGUSR1);
	}
	return 0;
}

