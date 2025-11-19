#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // for bool, true, false

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

// recursive search
bool recursiveSearch(struct Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;

    if (key < root->data)
        return recursiveSearch(root->left, key);
    else
        return recursiveSearch(root->right, key);
}

// iterative search
bool iterativeSearch(struct Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int main() {
    // Creating BST
    //    6
    //   / \
    //  2   8
    //     / \
    //    7   9
    struct Node* root = createNode(6);
    root->left = createNode(2);
    root->right = createNode(8);
    root->right->left = createNode(7);
    root->right->right = createNode(9);

    int key = 7;

    // Searching for key in the BST
    printf("Iterative Search: %d\n", iterativeSearch(root, key));
    printf("Recursive Search: %d\n", recursiveSearch(root, key));

    return 0;
}
