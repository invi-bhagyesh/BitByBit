/*
Implementing Stack using Linked List
Time Complexity: O(1) for push, pop and peek operations
Space Complexity: O(n) where n is the number of elements in the stack
last updated: 2024-06-10 -> Attempt no. 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

int isEmpty(Node* head){
    return head == NULL;
}
void push(Node** head, int new_data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = new_data;
    new_node -> next = (*head);
    *head = new_node;
}

void pop(Node** head){
    if(isEmpty(*head)){
        printf("Stack Underflow");
        return;}
    Node* temp = *head;
    *head = (*head) -> next;
    free(temp);
}

int peek(Node* head){
    if(!isEmpty(head)){
        return head->data;
    }
    return INT_MIN;
}

int main(){
    Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);   

    printf("%d", peek(head));
    pop(&head);
    printf("%d", peek(head));
    return 0;
}