# include <stdio.h>
# include <unistd.h>

int main(){
fork();
fork();
fork();
//printf("Process created.\n");
printf("Process PID: %d\n", getpid());
return 0;
}
