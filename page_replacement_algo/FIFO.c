//Write a C program to simulate Fist In First out Algorithm (FIFO) page replacement algorithm
//for the following reference string - 
//Reference String - 7 0 1 2 0 3 0 4
//Frames = 3

#include <stdio.h>
int main(){
printf("FIFO page replacement algorithm\n");
int  total_page;
int n;
printf("Enter the total number of page reference String: \n");
scanf("%d", &total_page);
int page_array[total_page];
for(int i = 0; i < total_page; i++){
printf("Enter the %d page reference string: \n", i+1);
scanf("%d", &page_array[i]);
}

printf("Enter the frames number: \n");
scanf("%d", &n);
int frames_array[n];
for(int i = 0; i < n ; i++){
frames_array[i] = -1;
}

int page_fault = 0;
int front = 0;

for (int i = 0; i < total_page; i++){
int found = 0;
//Check hit
for( int j = 0; j < n; j++){
if(frames_array[j] == page_array[i]){
found = 1;
break;
}
}
//Page fault
if(found == 0){
frames_array[front] = page_array[i];
front = (front + 1)%n;
page_fault++;
}

printf("\nFrames: ");
for(int i = 0; i < n ; i++){
printf("%d ", frames_array[i]);
}
}
//Display the result;
printf("\nTotal number of page fault: %d\n", page_fault);
return 0;

}
