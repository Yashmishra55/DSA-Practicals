#include <stdio.h>
#include <stdlib.h>

// Node for the book tree
struct Node {
    int data;
    struct Node *children; // Array of children nodes
    int numChildren;
};

// Function to create a new node
struct Node* createNode(int data, int numChildren) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->numChildren = numChildren;
    newNode->children = (struct Node*)malloc(numChildren * sizeof(struct Node));
    return newNode;
}

// Function to print nodes of the tree
void printNodes(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("Node: %d\n", root->data);

    for (int i = 0; i < root->numChildren; ++i) {
        printf("Child %d of Node %d:\n", i + 1, root->data);
        printNodes(&(root->children[i]));
    }
}

int main() {
    // Creating nodes for the book hierarchy
    struct Node* book = createNode(1, 2);

    // Chapters of the book
    book->children[0] = *createNode(11, 2); // Chapter 1
    book->children[1] = *createNode(12, 1); // Chapter 2

    // Sections of Chapter 1
    book->children[0].children[0] = *createNode(111, 2); // Section 1 of Chapter 1
    book->children[0].children[1] = *createNode(112, 1); // Section 2 of Chapter 1

    // Subsections of Section 1 of Chapter 1
    book->children[0].children[0].children[0] = *createNode(1111, 0); // Subsection 1 of Section 1 of Chapter 1
    book->children[0].children[0].children[1] = *createNode(1112, 0); // Subsection 2 of Section 1 of Chapter 1

    // Subsection of Section 2 of Chapter 1
    book->children[0].children[1].children[0] = *createNode(1121, 0); // Subsection 1 of Section 2 of Chapter 1

    // Section of Chapter 2
    book->children[1].children[0] = *createNode(121, 0); // Section 1 of Chapter 2

    // Printing nodes of the book tree
    printf("Nodes of the book tree:\n");
    printNodes(book);

    return 0;
}
