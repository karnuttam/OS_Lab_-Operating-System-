# include <stdio.h>
# define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

//check queue is full or not
int isFull(){
if((rear + 1)%SIZE == front){
return 1;
}else{
return 0;
}
};
//check queue is empty or not
int isEmpty(){
if(front == -1){
return 1;
}else{
return 0;
}
}

//enqueue
void enqueue(int value){
if(isFull()){
printf("Queue is full\n");
return;
}else{
if(front == -1){
front = 0;
}
rear = (rear + 1)%SIZE;
queue[rear] = value;
printf("The inserted value is %d\n", value);

};
};

//dequeue
void dequeue(){
if(isEmpty()){
printf("The queue is empty\n");
return;
}else{
printf("The deleted value is %d\n", queue[front]);
if(front == rear){
front = -1;
rear = -1;

}else{
front = (front +1) %SIZE;
};
};
};

//Display
void Display(){
if(isEmpty()){
printf("Queue is Empty\n");
return;

}else{
int i = front;
printf("Queue Elements: \n" );
while(1){
printf("%d ", queue[i]);
if(i == rear){
break;
}else{
i = (i + 1)%SIZE;
};
}
printf("\n");
}
}

//main function

int main(){
enqueue(10);
enqueue(15);
enqueue(20);
enqueue(25);
enqueue(30);

Display();
dequeue();
Display();
return 0;
}


