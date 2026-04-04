# include <stdio.h>
# include <unistd.h>
# include <signal.h>

void handle_sigint(int sig){
printf("\nSIGINT caught Press Ctrl+\\to exit.\n");
}
int main(){
signal(SIGINT, handle_sigint);
while(1){
printf("Process Running... PID=%d\n",getpid());
sleep(2);
}
return 0;
}
