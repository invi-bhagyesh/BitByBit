# include <stdio.h>
#include <stdlib.h>
//Node structure
typedef struct node{
    int data;
    struct node* next;
}node;

node* createNode(int item){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = item;
    newNode->next= NULL;
}
node* top = NULL;

//push
void push(int item){
    node* newNode = createNode(item);
    if (!newNode) printf("OVerflow");
    else{
        newNode->next=top; 
        top=newNode;
    }
}

//pop
void pop(){
    if (top==NULL){
        printf("EMPtY");
    }
    else{
        node* temp= top;
        top=top->next;
        free(temp);
    }
}

//peek
void peek(){
    if (top==NULL){
        printf("EMPTY");
    }
    else{
        printf("%d", top->data);
    }
}

//display
void peek(){
    if (top=NULL){
        printf("EMPTY");
    }
    else{
        node* temp=top;
        while(temp!=NULL){
            printf("%d->", temp->data);
            temp=temp->next;
        }
    }
}
