//Write a C program to simulate LRU page replacement algorithm for the following 
//reference string - 
//Reference string: 7 0 1 2 0 3 0 4
//Frames = 3

#include <stdio.h>
int main(){
printf("The Least Recently Page used algorithm (LRU): \n");
int total_page;
int frames;
int current_index;

printf("Enter the total number of reference string: \n");
scanf("%d", &total_page);
int ref_arr[total_page];

//Enter the reference string
for(int i = 0; i < total_page; i++){
printf("Page %d: ",i+1);
scanf("%d", &ref_arr[i]);
}
printf("Enter the total number of frames: \n");
scanf("%d",&frames);

int frames_array[frames];
//initialize the frames array
for(int j = 0; j < frames; j++){
frames_array[j] = -1;
}
//write condition
int page_fault = 0;
for(int i = 0; i < total_page; i++){
int found = 0;//flag variable
for(int  j = 0; j < frames; j++){
//Check hit
if(frames_array[j] == ref_arr[i]){
found = 1;
break;
}
}
//page fault
if(found == 0){
int LRU_index = -1;
int min = i;//Farthest in past
for(int j = 0; j < frames ; j++){
int k;
//search backward;
for(k = i - 1; k >= 0; k--){
if(frames_array[j] == ref_arr[k]){
break;
}
}
//if page never used before
if(k == -1){
LRU_index = j;
break;
}

//least recently used
if(k < min){
min = k;
LRU_index = j;
}
}
frames_array[LRU_index] = ref_arr[i];
page_fault++;
}

printf("\nFrames: ");
for(int j = 0; j < frames; j++){
printf("%d ", frames_array[j]);

}
}
printf("\nTotal Page fault: %d\n", page_fault);


return 0;
}
