#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid = fork();
	if(pid == 0){
		printf("Child exiting\n");
	}else{
		wait(NULL);
		printf("Parent after wait\n");
	}
	return 0;
}
