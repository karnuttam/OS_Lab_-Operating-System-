# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>

int main()
{
//Using fork() function for process duplication
fork();
fork();
fork();
printf("Hello Uttam Singh\nPID: %d\n",getpid());

return 0;
}
