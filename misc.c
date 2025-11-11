#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// =======================================================
/// MODULE 1 — STACK (LIFO, LINKED LIST)
/// =======================================================
typedef struct Stack {
    int id;
    char name[50];
    struct Stack* next;
} Stack;

void push(Stack** top, int id, char* name) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed: %d - %s\n", id, name);
}

void pop(Stack** top) {
    if (*top == NULL) {
        printf("Stack empty\n");
        return;
    }
    Stack* temp = *top;
    printf("Popped: %d - %s\n", temp->id, temp->name);
    *top = (*top)->next;
    free(temp);
}

void peek(Stack* top) {
    if (!top) printf("Stack empty\n");
    else printf("Top: %d - %s\n", top->id, top->name);
}

void displayStack(Stack* top) {
    if (!top) {
        printf("Stack empty\n");
        return;
    }
    printf("Stack contents:\n");
    while (top) {
        printf("%d - %s\n", top->id, top->name);
        top = top->next;
    }
}

Stack* reverseStack(Stack* top) {
    Stack *prev = NULL, *curr = top, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/// =======================================================
/// MODULE 2 — QUEUE (FIFO, LINKED LIST)
/// =======================================================
typedef struct Queue {
    int id;
    char name[50];
    struct Queue* next;
} Queue;

void enqueue(Queue** front, Queue** rear, int id, char* name) {
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Enqueued: %d - %s\n", id, name);
}

void dequeue(Queue** front, Queue** rear) {
    if (*front == NULL) {
        printf("Queue empty\n");
        return;
    }
    Queue* temp = *front;
    printf("Dequeued: %d - %s\n", temp->id, temp->name);
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
}

void peekQueue(Queue* front) {
    if (!front) printf("Queue empty\n");
    else printf("Front: %d - %s\n", front->id, front->name);
}

void displayQueue(Queue* front) {
    if (!front) {
        printf("Queue empty\n");
        return;
    }
    printf("Queue contents:\n");
    while (front) {
        printf("%d - %s\n", front->id, front->name);
        front = front->next;
    }
}

int countQueue(Queue* front) {
    int count = 0;
    while (front) {
        count++;
        front = front->next;
    }
    return count;
}

/// =======================================================
/// MODULE 3 — LINKED LIST (SINGLY)
/// =======================================================
typedef struct Node {
    int id;
    char name[50];
    struct Node* next;
    struct Node* left;
    struct Node* right;
} Node;

Node* insertAtBeginning(Node* head, int id, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = head;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertAtEnd(Node* head, int id, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->left = newNode->right = NULL;

    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteFromBeginning(Node* head) {
    if (!head) {
        printf("List empty\n");
        return NULL;
    }
    Node* temp = head;
    printf("Deleted: %d - %s\n", temp->id, temp->name);
    head = head->next;
    free(temp);
    return head;
}

Node* deleteFromEnd(Node* head) {
    if (!head) {
        printf("List empty\n");
        return NULL;
    }
    if (!head->next) {
        printf("Deleted: %d - %s\n", head->id, head->name);
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    printf("Deleted: %d - %s\n", temp->next->id, temp->next->name);
    free(temp->next);
    temp->next = NULL;
    return head;
}

void searchList(Node* head, int key) {
    while (head) {
        if (head->id == key) {
            printf("Found: %d - %s\n", head->id, head->name);
            return;
        }
        head = head->next;
    }
    printf("Not found\n");
}

void displayList(Node* head) {
    if (!head) {
        printf("List empty\n");
        return;
    }
    printf("Linked List contents:\n");
    while (head) {
        printf("%d - %s\n", head->id, head->name);
        head = head->next;
    }
}

int countNodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* reverseList(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/// =======================================================
/// MODULE 4 — BINARY SEARCH TREE (ID-BASED)
/// =======================================================
Node* createTreeNode(int id, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* insertBST(Node* root, int id, char* name) {
    if (!root) return createTreeNode(id, name);
    if (id < root->id)
        root->left = insertBST(root->left, id, name);
    else if (id > root->id)
        root->right = insertBST(root->right, id, name);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int id) {
    if (!root) return root;
    if (id < root->id)
        root->left = deleteNode(root->left, id);
    else if (id > root->id)
        root->right = deleteNode(root->right, id);
    else {
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d - %s\n", root->id, root->name);
    inorder(root->right);
}
void preorder(Node* root) {
    if (!root) return;
    printf("%d - %s\n", root->id, root->name);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d - %s\n", root->id, root->name);
}

/// BFS (using linked queue)
typedef struct TreeQueue {
    Node* data;
    struct TreeQueue* next;
} TreeQueue;

void enqueueTree(TreeQueue** front, TreeQueue** rear, Node* node) {
    TreeQueue* newNode = (TreeQueue*)malloc(sizeof(TreeQueue));
    newNode->data = node;
    newNode->next = NULL;
    if (*rear == NULL)
        *front = *rear = newNode;
    else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

Node* dequeueTree(TreeQueue** front, TreeQueue** rear) {
    if (*front == NULL) return NULL;
    TreeQueue* temp = *front;
    Node* node = temp->data;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return node;
}

void BFS(Node* root) {
    if (!root) {
        printf("Tree empty\n");
        return;
    }
    TreeQueue *front = NULL, *rear = NULL;
    enqueueTree(&front, &rear, root);
    printf("BFS (Level Order):\n");
    while (front) {
        Node* curr = dequeueTree(&front, &rear);
        printf("%d - %s\n", curr->id, curr->name);
        if (curr->left) enqueueTree(&front, &rear, curr->left);
        if (curr->right) enqueueTree(&front, &rear, curr->right);
    }
}

/// DFS (using linked stack)
typedef struct TreeStack {
    Node* data;
    struct TreeStack* next;
} TreeStack;

void pushTree(TreeStack** top, Node* node) {
    TreeStack* newNode = (TreeStack*)malloc(sizeof(TreeStack));
    newNode->data = node;
    newNode->next = *top;
    *top = newNode;
}
Node* popTree(TreeStack** top) {
    if (!*top) return NULL;
    TreeStack* temp = *top;
    Node* node = temp->data;
    *top = (*top)->next;
    free(temp);
    return node;
}

void DFS(Node* root) {
    if (!root) {
        printf("Tree empty\n");
        return;
    }
    TreeStack* top = NULL;
    pushTree(&top, root);
    printf("DFS (Preorder style):\n");
    while (top) {
        Node* curr = popTree(&top);
        printf("%d - %s\n", curr->id, curr->name);
        if (curr->right) pushTree(&top, curr->right);
        if (curr->left) pushTree(&top, curr->left);
    }
}

/// =======================================================
/// MAIN MENU
/// =======================================================
int main() {
    Stack* stack = NULL;
    Queue *front = NULL, *rear = NULL;
    Node* list = NULL;
    Node* tree = NULL;
    int choice, sub, id;
    char name[50];

    do {
        printf("\n=========== MAIN MENU ===========\n");
        printf("1. Stack\n2. Queue\n3. Linked List\n4. Tree (BST)\n5. Traversals (BFS/DFS)\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n--- STACK MENU ---\n1.Push 2.Pop 3.Peek 4.Display 5.Reverse 0.Back\n");
            scanf("%d", &sub);
            if (sub == 1) { printf("Enter ID & Name: "); scanf("%d %s", &id, name); push(&stack, id, name); }
            else if (sub == 2) pop(&stack);
            else if (sub == 3) peek(stack);
            else if (sub == 4) displayStack(stack);
            else if (sub == 5) { stack = reverseStack(stack); printf("Stack reversed\n"); }
            break;

        case 2:
            printf("\n--- QUEUE MENU ---\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Count 0.Back\n");
            scanf("%d", &sub);
            if (sub == 1) { printf("Enter ID & Name: "); scanf("%d %s", &id, name); enqueue(&front, &rear, id, name); }
            else if (sub == 2) dequeue(&front, &rear);
            else if (sub == 3) peekQueue(front);
            else if (sub == 4) displayQueue(front);
            else if (sub == 5) printf("Queue count: %d\n", countQueue(front));
            break;

        case 3:
            printf("\n--- LINKED LIST MENU ---\n1.InsertBeg 2.InsertEnd 3.DeleteBeg 4.DeleteEnd 5.Search 6.Display 7.Reverse 8.Count 0.Back\n");
            scanf("%d", &sub);
            if (sub == 1) { printf("Enter ID & Name: "); scanf("%d %s", &id, name); list = insertAtBeginning(list, id, name); }
            else if (sub == 2) { printf("Enter ID & Name: "); scanf("%d %s", &id, name); list = insertAtEnd(list, id, name); }
            else if (sub == 3) list = deleteFromBeginning(list);
            else if (sub == 4) list = deleteFromEnd(list);
            else if (sub == 5) { printf("Enter ID: "); scanf("%d", &id); searchList(list, id); }
            else if (sub == 6) displayList(list);
            else if (sub == 7) { list = reverseList(list); printf("List reversed\n"); }
            else if (sub == 8) printf("Node count: %d\n", countNodes(list));
            break;

        case 4:
            printf("\n--- TREE MENU ---\n1.Insert 2.Delete 3.Inorder 4.Preorder 5.Postorder 6.FindMin 7.BFS 8.DFS 0.Back\n");
            scanf("%d", &sub);
            if (sub == 1) { printf("Enter ID & Name: "); scanf("%d %s", &id, name); tree = insertBST(tree, id, name); }
            else if (sub == 2) { printf("Enter ID to delete: "); scanf("%d", &id); tree = deleteNode(tree, id); }
            else if (sub == 3) inorder(tree);
            else if (sub == 4) preorder(tree);
            else if (sub == 5) postorder(tree);
            else if (sub == 6) { Node* min = findMin(tree); if (min) printf("Min: %d - %s\n", min->id, min->name); }
            else if (sub == 7) BFS(tree);
            else if (sub == 8) DFS(tree);
            break;

        case 5:
            printf("\n--- TRAVERSALS ---\n1.BFS 2.DFS\n");
            scanf("%d", &sub);
            if (sub == 1) BFS(tree);
            else if (sub == 2) DFS(tree);
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 0);
    return 0;
}
/// =======================================================
/// =======================================================
/// =======================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CNode {
    int id;
    char name[50];
    struct CNode* next;
} CNode;

CNode* insertAtEnd(CNode* head, int id, char* name) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->id = id;
    strcpy(newNode->name, name);

    if (!head) {
        newNode->next = newNode; // circular link
        return newNode;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return head;
}

CNode* insertAtBeginning(CNode* head, int id, char* name) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->id = id;
    strcpy(newNode->name, name);
    if (!head) {
        newNode->next = newNode;
        return newNode;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

CNode* deleteNode(CNode* head, int id) {
    if (!head) {
        printf("List empty\n");
        return NULL;
    }

    CNode *curr = head, *prev = NULL;
    do {
        if (curr->id == id) {
            if (curr == head && curr->next == head) {
                free(curr);
                return NULL; // only one node
            }
            if (curr == head) {
                CNode* temp = head;
                while (temp->next != head)
                    temp = temp->next;
                head = head->next;
                temp->next = head;
                free(curr);
                return head;
            } else {
                prev->next = curr->next;
                free(curr);
                return head;
            }
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    printf("Node not found\n");
    return head;
}

void displayCLL(CNode* head) {
    if (!head) {
        printf("Circular list empty\n");
        return;
    }
    CNode* temp = head;
    printf("Circular Linked List:\n");
    do {
        printf("%d - %s\n", temp->id, temp->name);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    CNode* head = NULL;
    int choice, id;
    char name[50];

    do {
        printf("\n--- CIRCULAR LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete by ID\n4. Display\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter ID and Name: ");
            scanf("%d %s", &id, name);
            head = insertAtBeginning(head, id, name);
            break;
        case 2:
            printf("Enter ID and Name: ");
            scanf("%d %s", &id, name);
            head = insertAtEnd(head, id, name);
            break;
        case 3:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            head = deleteNode(head, id);
            break;
        case 4:
            displayCLL(head);
            break;
        }
    } while (choice != 0);
    return 0;
}
