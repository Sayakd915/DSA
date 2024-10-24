#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

int isEmpty(){
    return front == -1;
}

int isFull(){
    return rear == MAX - 1;
}

void enqueue(int value){
    if(isFull()){
        printf("Queue is full\n");
        return;
    }
    if(isEmpty()){
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%d enqueued to the queue\n", value);
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    int value = queue[front];
    if(front == rear){
        front = rear = -1;
    } else {
        front ++;
    }
    return value;
}

void displayQueue(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for(int i = front; i<=rear;i++){
        printf("%d ", queue[i]);
    } printf("\n");
}

int main(){
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    displayQueue();
    dequeue();
    displayQueue();
    enqueue(60);
    return 0;
}