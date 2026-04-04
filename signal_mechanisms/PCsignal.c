# include <stdio.h>
# include <unistd.h>
# include <signal.h>

void child_handler(int sig){
printf("Child process received the signal.\n");
}

int main(){
pid_t pid = fork();
if(pid == 0){
signal(SIGUSR1, child_handler);
while(1){
pause();
}
}else{
sleep(5);
kill(pid, SIGUSR1);
}
return 0;
}

