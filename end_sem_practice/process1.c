#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
int i = 0;
int count = 5;
void handle_signal(int sig){
i++;
if(i >= count){
	printf("\nSIGINT received %d times. Exiting.....\n", i);
	exit(0);
}else{
	printf("Signal caught (%d/%d)\n", i, count);

}
}
int main(){
	signal(SIGINT, handle_signal);
	while(1){
		printf("Process is running.\nProcess ID: %d\n",getpid());
		sleep(2);
	}
	return 0;
}
