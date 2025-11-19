#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* createNode(int item){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
node* head = NULL;
node* newNode;
node* temp;
void insertBeginning(int item){
    node* newNode=createNode(item);
    if (newNode==NULL){
        printf("OVERFLOW");
    }
    else{
        newNode->next = head;
        if (head!=NULL){
        head->prev=newNode;
        }
        head = newNode;
    }
}

void end(int item){
    node* newNode = createNode(item);    
    if (newNode==NULL) printf("OVERFLOW");
    else{
        if(head==NULL){
            head = newNode;
        }
        else{
            temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            printf("Node inserted at the end";)
        }
    }
}


void middle(int item, int loc){
    newNode = createNode(item);
    int i;
    if (newNode==NULL){printf("OVERFLOW");}
    else if (head==NULL){
        head = newNode;
    }
    else{
        temp = head;
        for (int i=1;i<loc;i++){
            if (temp==NULL) printf("exceeding list size");
            temp=temp->next;
        }
        newNode->next = temp->next;     
        newNode->prev= temp;
        if(temp->next!=NULL){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

void delete_beginning(){
    if(head==NULL){
        printf("list is empty");
    }
    else{
        temp = head;
        head=head->next;
        if (head!=NULL){
        head->prev = NULL;
        }
        free(temp);
    }
}

void delete_end(){
    if (head==NULL){
        printf("list is empty");
    }
    else{
        temp =head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        if (temp->prev!=NULL){
            temp->prev->next= NULL;
        }
        else{head=NULL;}
        free(temp);
        printf("Node deleted from end");
    }
}

void deleted_middle(int loc){
    if (head=NULL){
        printf("list is empty");
    }
    else{
        temp=head;
        for (int i=0; i<loc;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        temp->next->prev = temp;
        temp= temp->next;
        free(temp);

    }
}