//Zombie: Child has terminated, but parent hasn't collected its exit status.

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

int main(){
if (fork() == 0){
printf("Child exiting\n");
}else{
sleep(10);
printf("Parent sleeping\n");
//wait(NULL);//Parent waits for child to finish
//printf("Parent after wait\n");
}
return 0;
}
