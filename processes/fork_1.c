// # unistd.h (short for UNIX standard header) is a header file in C that provides access to POSIX operating system API functions.
// POSIX stands for Portable Operating System Interface
//POSIX is a standard that defines how an operating system should behave so that programs can run on different Unix-like systems without modification.

//fork() creates a new process (child) by duplicating the calling process (parent)

# include <stdio.h>
# include <unistd.h>

int main(){
fork();
printf("Hello from processes!\n");
return 0;
}
