#define MAX 6
int stack[MAX], top=-1;


//push 
void push(int item){
    if (top==MAX-1){
        printf("STACK OVERFLOW");
    }
    else{
        stack[++top]=item;
    }

}

//pop
void pop(){
    if (top==-1){
        printf("empty");
    }
    else{
        printf("%d",stack[top--]);
    }
}


//peek
void peek(){
    if (top==-1){
        printf("empty");
    }
    else{
        printf("%d", stack[top]);
    }
}

//isEmpty
void isEmpty(){
    if(top==-1){
        printf("Stack is empty");
    }
}


//display
void display(){
    for(int i=0; i<MAX;i++){
        printf("%d",stack[i]);
    }
}

int main(){
    int choice;
    int item;

    do{
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Is Empty");
        printf("\n5. Display");
        printf("\n-1. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                isEmpty();
                break;

            case 5:
                display();
                break;

            case -1:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice");
        }
    }
    while(choice != -1);

    return 0;
}
