#include<stdio.h>
#include<unistd.h>

int main(){
	while(1){
		printf("Process is running.\n Process ID: %d\n", getpid());
		sleep(2);
	}
	return 0;
}
