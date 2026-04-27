#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig){
	printf("SIGINT caught! To terminate press Ctrl+\\n");
}
int main(){
		signal(SIGINT, sigint_handler);
		while(1){
			printf("Process is running.\nProcess ID: %d\n", getpid());
			sleep(2);
		}
		return 0;
	}
