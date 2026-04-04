# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int main(int argc, char *argv){
printf("PID of exe1.c = %d\n",getpid());
char *args[] = {"Hello", "Uttam Singh", NULL};
execv("./exe2", args);
printf("Back to exe1.c\n");
return 0;
}
