# include <signal.h>
# include <unistd.h>
# include <stdio.h>

void alarm_handler(int sig){
printf("\nTimes up! Alarm signal received.\n");
}

int main(){
signal(SIGALRM, alarm_handler);
alarm(5);

printf("Waiting to receive the alarm signal\n");
pause();
return 0;
}
