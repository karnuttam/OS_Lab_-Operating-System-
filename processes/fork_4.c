//Parent and child do not share memory
//After fork()
//Two processes are created:
//      1.Parent process
//      2.Child process
//Each process gets its own copy of variable x.

# include <stdio.h>
# include <unistd.h>

int main(){
pid_t pid = fork();
int x = 10;
if (pid == 0){
x = x + 10;
printf("Child process: x = %d\n", x);
}else{
x = x - 5;
printf("Parent process: x = %d\n", x);
}
return 0;
}
