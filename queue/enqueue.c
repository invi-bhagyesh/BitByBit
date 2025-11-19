#define MAX 5

int queue[MAX];
int front, rear;

//isEmpty
void isEmpty(){
    return front==-1;
}

void isFull(){
    return rear==MAX-1;
}

void enqueue(int item){
    if (isEmpty) printf("empty");
    if (isFull) printf("full");
    queue[++rear]=item;
}

int dequeue(){
    if (front==-1){printf("UNDERFLOW");}
    int item = queue[front];
    if (front==rear) front=rear=-1;
    else{
        front++;
    }
    return item;
}

int peek(){
    if(isEmpty)printf("Empty");
    exit(1);
    return queue[front];
}

