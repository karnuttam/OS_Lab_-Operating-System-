# include <stdio.h>
# include <unistd.h>

int main(){
int a =  5; 
int b = 10;
fork();
a = a + 5;
fork();
b = b - 5;
printf("PID: %d\n | a = %d\n, b = %d\n", getpid(), a, b);
return 0;
}
