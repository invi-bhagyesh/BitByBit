#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int insertBeforeHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) return -1; // malloc failed

    if (*head == NULL) { // list is empty
        *head = newNode;
        return 0;
    }

    // not empty    
    newNode->next = *head;
    *head = newNode;
    return 0;
}

int deleteHead(struct Node** head) {
    if (*head == NULL) return -1; // handle empty list

    struct Node* temp = *head;
    *head = (*head)->next; // parentheses are needed here
    free(temp);
    return 0;
}

int isEmpty(struct Node** stack) {
    return *stack == NULL;
}

void push(struct Node** stack, int data) {
    if (insertBeforeHead(stack, data)) {
        printf("Memory Overflow\n");
    }
}

int pop(struct Node** stack) {
    if (isEmpty(stack)) {
        printf("Underflow\n");
        return -1;
    }
    deleteHead(stack);
    return 0;
}

int peek(struct Node** stack) {
    if (!isEmpty(stack)) {
        return (*stack)->data;
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

void printStack(struct Node** stack) {
    struct Node* temp = *stack;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack = NULL; // ❗ 'Node', not 'node'

    // Push elements into the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    // Print the stack
    printf("Stack: ");
    printStack(&stack);

    // Pop elements from the stack
    pop(&stack);
    pop(&stack);

    // Print the stack after deletion of elements
    printf("After popping two elements:\nStack: ");
    printStack(&stack);

    // Peek the top element
    printf("Top element: %d\n", peek(&stack));

    return 0;
}
