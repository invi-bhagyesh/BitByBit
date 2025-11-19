#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

typedef struct Queue{
    node* front;
    node* rear;
}queue;

node * createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode==NULL)return NULL;
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

//create queue
queue *createQueue(){
    queue *newQueue = (queue*)malloc(sizeof(queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}
int isEmpty(queue *q){
    return q->front == NULL;
}

void enqueue(queue *q, int data){
    node *newNode = createNode(data);

    //exceptions
    if (!newNode) printf("Overflow!");
    if(q->rear==NULL){
        q->front=q->rear=newNode; return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(queue *q){
    if(isEmpty(q)){ printf("Underflow"); return -1;}

    node *temp = q->front;
    q->front= q->front->next;
    if(q->front==NULL) q->rear=NULL;
    int data = temp->data;
    free(temp);
    return data;
}

int peek(queue *q){
    if(isEmpty(q)) return -1;
    return q->front->data;
}

void printQueue(queue *q){
    node *temp = q->front;
    while(temp!=NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    // Create a new queue
    queue *q = createQueue();

    // Enqueue elements into the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Print the queue
    printf("Queue: ");
    printQueue(q);

    // Dequeue elements from the queue
    dequeue(q);
    dequeue(q);

    // Print the queue after deletion of elements
    printf("Queue: ");
    printQueue(q);

    return 0;
}

