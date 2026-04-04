//Two way IPC (Parent<->Child) using kill()
//Parent and child communicate using SIGUSR1 and SIGUSR2
//Parent -> child: SIGUSR1
//Child -> parent: SIGUSR2
//Both processes have their own signal handlers
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

pid_t pid;

void parent_handler(int sig){
if(sig == SIGUSR2){
printf("Parent process: Received signal SIGUSR2 from child.\n");
}
}

void child_handler(int sig){
if (sig == SIGUSR1){
printf("Child process: Received signal SIGUSR1 from parent.\n");
kill(getppid(), SIGUSR2); // Send signal back to parent
}
}

int main(){
pid = fork(); //Create child process
if(pid == 0){
signal(SIGUSR1, child_handler);
printf("Child process: Waiting for signal from parent.\n");
pause();
}else{
signal(SIGUSR2, parent_handler);
sleep(2);//Ensuring child is ready
printf("Parent Process:Sending SIGUSR1 to child\n");
kill(pid, SIGUSR1);
pause(); //Wait for child response
}
return 0;
}


