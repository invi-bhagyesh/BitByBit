/*
Dynamic Stack Implementation in C
Time Complexity: O(1) for push, pop and peek operations
Space Complexity: O(n) where n is the number of elements in the stack
last updated: 2024-06-10 -> Attempt no. 1
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top, cap;
    int* array;
}Stack;

Stack* createStack(int cap){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack -> cap = cap;
    stack -> top = -1;
    stack -> array = (int*)malloc(stack->cap * sizeof(int));
    return stack;
}

void deleteStack(Stack* stack){
    free(stack->array);
    free(stack);
}   

int isFull(Stack* stack){
    return stack->top == stack->cap - 1;
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, int item){
    if(isFull(stack)){
        printf("Stack Overflow");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(Stack* stack){
    if(!isEmpty(stack)){
        return stack->array[stack->top];
    }
    return -1;
}

int main(){
    Stack* stack = createStack(100);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d\n", peek(stack));
    printf("%d\n", pop(stack));
    printf("Elements present in stack : ");
    while(!isEmpty(stack))
        printf("%d ",pop(stack));
    printf("\n");


    deleteStack(stack);
    return 0;
}