#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Queue{
    struct Node*front,*rear;
};

struct Node *createNode(int value){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue(){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, int value){
    struct Node *temp = createNode(value);
    if(q->rear == NULL){
        q->front = q->rear = temp;
        printf("%d enqueued to the queue\n", value);
        return;
    }
    q->rear->next = temp;
    q->rear =  temp;
    printf("%d enqueued to the queue\n", value);
}

void dequeue(struct Queue *q){
    if(q->front == NULL){
        printf("Queue is empty. Cannot dequeue\n");
        return;
    }
    struct Node *temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear=NULL;
    }
    printf("Dequeued element is %d\n", temp->data);
    free(temp);
}

void displayQueue(struct Queue *q){
    if(q->front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = q->front;
    printf("Queue elements are: ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Queue *q = createQueue();
    dequeue(q);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    displayQueue(q);
    dequeue(q);
    displayQueue(q);
    return 0;
}