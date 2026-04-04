# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void signal_handler(int sig){
printf("Received signal: %d\n", sig);
}
int main(){
struct sigaction sa;
sa.sa_handler = signal_handler;//Set handler function
sigemptyset(&sa.sa_mask); //Clear mask
sa.sa_flags=0; // No special flags
sigaction(SIGUSR1, &sa, NULL);//Register handler for SIGUSR1
printf("Received Signal PID: %d\n", getpid());
printf("Waiting for signal......\n");
while(1){
pause(); //Wait for signal
}
return 0;
}
