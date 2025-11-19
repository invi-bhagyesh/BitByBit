#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

struct Node* createNode(int item) {
    struct Node* newNode = (struct Node* )malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
};

Node* head = NULL;

void beginInsert(){
    int item;
    scanf("%d", &item);
    Node* newNode = createNode(item);
    if (newNode == NULL){
        printf("OVERFLOW");
    }
    else{
        newNode->next = head;
        head = newNode;
        printf("NewNode Inserted");
    }
}

void lastInsert(){
    int item;
    Node* temp;
    scanf("%d", &item);
    Node* lastNode = createNode(item);
    if(lastNode == NULL){
        printf("OVERFLOW");
    }
    else{
        lastNode->next=NULL;
        if (head==NULL){
            head = lastNode;
            printf("node inserted");
        }
        else{
            temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = lastNode;
            printf("node Inserted at the last");
        }
    }
}

void middleInsert(){
    int i,loc,item;
    scanf("%d", &item);
    Node* middleNode = createNode(item);
    if (middleNode==NULL){
        printf("Overflow");
    }
    else{
        scanf("%d", &loc);
        Node* temp =head;
        for (i=0; i<loc; i++){
            if (temp==NULL){printf("Exceeds list size");}
            temp = temp->next;
        } 
        middleNode->next = temp->next;
        temp->next = middleNode;
    }
}

void delete_front(){
    Node* temp = head;
    if (head==NULL){
        printf("list empty");
    }
    head = temp->next;
    free(temp);
}

void delete_last(){
    Node* temp = head;
    Node* temp1;
    if(head=NULL){
        printf("list empty");
    }
    else if(head->next==NULL){
        head=NULL;
        free(temp);
        printf("Only one Node deleted");
    }
    //Multiple Nodes
    else{
        while(temp->next!=NULL){
            temp1 = temp;
            temp= temp->next;
        }
        temp1->next= NULL;
        free(temp);
    }
}

void delete_middle(){
    int i, loc;
    Node* temp1;
    Node* temp=head;
    if(head==NULL){
        printf("OVERFLOW");
    }
    if(loc=1){
        head=head->next;
        free(temp);
    }
    else{
        for (i=1; i<loc; i++){
            temp1 = temp;
            temp=temp->next;
        }
        temp1->next = temp->next;
        freee(temp);
    }
}

void search(){
    Node* temp = head;
    int item;
    scanf("%d", &item);
    if (head = NULL){
        printf("Empty list");
    }
    else{
        int i=1, found=0;
        while(temp!=NULL){
            if(temp->data == item){
                printf("item found at position %d", i);
                i++;
                int found = 1;
            }
            temp = temp->next;
        }
        if (found==0){
            printf("Not found");
        }

    }
}

void reverse_list(){
    Node* prev=NULL, *curr=head, *next=NULL;
    if (head ==NULL){
        prinf("List is empty");
    }
    else{
        while(curr!=NULL){
            // 
        }
    }
}

void display_ll(){
    Node* temp = head;
    if (head==NULL){

        printf("Empty list");
    }
    else{
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("->NULL");
    }
}
Node* temp, *head1=NULL, *head2=NULL;

void concatenate(){
    if (head1 ==NULL){
        printf("empty list");
        head1=head2;
        return;
    }
    if (head2==NULL){
        return; 
    }
    else{
        temp= head1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = head2;

    }
}