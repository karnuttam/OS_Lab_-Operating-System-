#include<stdio.h>
int main(){
printf("=====FIFO Page replacement algorithm=======\n");
int total_page;
int frames;



printf("Enter the total number of pages: \n");
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
int front = 0;

for(int i = 0; i < total_page; i++){
int found = 0;
for(int j = 0; j < frames; j++){
if(frame_arr[j] == page_arr[i]){
found = 1;
break;
}
}
if(found == 0){
frame_arr[front] = page_arr[i];
front = (front + 1)%frames;
page_fault++;

}
printf("\nFrames: ");
for(int j = 0; j < frames; j++){
printf("%d ", frame_arr[j]);
}
}
printf("Page fault: %d\n", page_fault);
return 0;
}

