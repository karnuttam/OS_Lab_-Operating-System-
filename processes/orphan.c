//Orphan process 
//When the parent exits, the child is still running
//The child loses its original parent
//The OS reassigns the child to: init (PID 1) or systemd (commonly PID 1)
//This makes the child an orphan process.
# include <stdio.h>
# include <unistd.h>

int main(){
pid_t pid = fork();
if (pid > 0){
printf("Parent process\n");
printf("PID: %d\n", getpid());
printf("Parent exiting...\n");

}else{
sleep(5);//Ensures parent exits first
printf("Child Process\n");
printf("PID: %d, Parent PID: %d\n", getpid(), getppid());
}
return 0;
}

