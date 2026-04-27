#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Usage: ./a.out <number>\n");
		return 1;
	}
	int num = atoi(argv[1]);
	printf("The number passed through commandline is %d\n", num);
	int square = num*num;
	printf("The square of %d is %d\n", num, square);
	int fact = 1;
	for(int i = 1; i <= num; i++){
		fact = fact*i;
	}
	printf("The factorial of the given number is %d\n", fact);
	
	double result = sqrt(num);
	printf("The square root of the given number %d is %.2f\n", num, result);





	return 0;
}
