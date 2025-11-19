#define MAX 100

int priorityQueue[MAX];
int size=0;
void insert(int item){
    if (size==MAX){
        printf("QUEUE is full");
    }
    else{
        priorityQueue[++size]=item;
    }
}

int deleteMax(){
    int maxInd=0;
    for (int i =0;i<size;i++){
        if(priorityQueue[i]>priorityQueue[maxInd]){
            maxInd=i;
        }
    }
    int maxElemnet = priorityQueue[maxInd];
    for (int i=maxInd;i<size-1;i++){
        priorityQueue[i]=priorityQueue[i+1];
    }
    size--;
    return maxElemnet;
}

// Display the priority queue
void display() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", priorityQueue[i]);
    }    printf("\n"); }