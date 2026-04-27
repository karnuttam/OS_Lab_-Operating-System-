#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid = fork();
	if (pid == 0){
		printf("Child is exiting\n");
	}else
	{
		sleep(10);
		printf("Parent is waiting\n");
	}
	return 0;
}
