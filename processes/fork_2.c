# include <unistd.h>
# include <stdio.h>

int main(){
pid_t pid = fork();
if(pid == 0){
printf("Child process.\n");
printf("Child process PID: %d\n", getpid());
}else{
printf("Parent Process.\n");
printf("Parent Process PID: %d\n", getpid());
}
return 0;
}

//The parent and child process execution order is not fixed or guaranteed.
//It is non-deterministic and depends entirely on the operating system's process scheduler.
