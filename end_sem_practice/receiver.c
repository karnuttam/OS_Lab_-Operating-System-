#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void signal_handler(int sig){
	printf("Signal is received. PID: %d\n", sig);
}

int main(){
	struct sigaction sa;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	printf("Receiver PID: %d\n", getpid());
	printf("Waiting for signal...\n");
	while(1){
		pause();
	}
}

