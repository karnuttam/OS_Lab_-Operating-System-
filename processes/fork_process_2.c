# include <stdio.h>
# include <unistd.h>
int main(){
pid_t pid = fork();
int a = 5;
int b = 10;
if(pid == 0){
a = a + 2;
}else{
b = b + 2;
}
if( pid == 0){
a  = a + 3;
}else{
b = b + 3;
}
printf("PID: %d\n | a = %d\n b = %d\n", getpid(), a, b);
return 0;
}
