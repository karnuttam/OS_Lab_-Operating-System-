#include<stdio.h>

int main(){
printf("====LRU Page replacement algorithm=====\n");
int total_page;
int frames;

printf("Enter the total number of page: \n");
scanf("%d", &total_page);
int page_arr[total_page];

for(int i = 0; i < total_page; i++){
printf("Enter the %d page: \n", i+1);
scanf("%d", &page_arr[i]);
}
printf("Enter the total number of frames: \n");
scanf("%d", &frames);
int frame_arr[frames];
for(int i = 0; i < frames; i++){
frame_arr[i] = -1;
}


int page_fault = 0;
for(int i = 0; i <total_page; i++){
int found = 0;
//page hit check
for(int j = 0; j < frames; j++){
if(frame_arr[j] == page_arr[i]){
found = 1;
break;
}
}

//page fault check;
if (found == 0){
int LRU_index = -1;
int min = i;
for(int j = 0; j < frames; j++){
int k;
//search backward
for(k = i - 1; k >= 0; k--){
if(frame_arr[j] == page_arr[k]){
break;
}
}
//if page never used
if(k ==-1){
LRU_index = j;
break;
}
//least recently used
if(k < min){
min = k;
LRU_index = j;
}
}
frame_arr[LRU_index] = page_arr[i];
page_fault++;
}
printf("\nFrames: ");
for (int j = 0; j < frames; j++){
printf("%d ", frame_arr[j]);

}
}
printf("Page_fault: %d\n", page_fault);


return 0;
}

