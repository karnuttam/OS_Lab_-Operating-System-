# include <stdio.h>
# include <unistd.h>
int main(){
while(1){
printf("Processing running...PID=%d\n", getpid());
sleep(2); 
}
return 0;
}
