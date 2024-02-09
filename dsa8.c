#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the number of nodes in the longest path
int longestPath(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftDepth = longestPath(root->left);
        int rightDepth = longestPath(root->right);
        return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
    }
}

// Function to find the minimum data value in the BST
int findMin(struct Node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return -1; // Return a sentinel value to indicate empty tree
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to swap left and right pointers at every node
struct Node* swapLRPointers(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    // Swap left and right pointers
    struct Node* temp = root->left;
    root->left = swapLRPointers(root->right);
    root->right = swapLRPointers(temp);

    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes into the BST
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int i, n = sizeof(values) / sizeof(values[0]);
    for (i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // Inserting a new node (value: 9)
    root = insert(root, 9);

    // Finding number of nodes in longest path
    printf("Number of nodes in the longest path: %d\n", longestPath(root));

    // Finding minimum data value in the tree
    printf("Minimum data value found in the tree: %d\n", findMin(root));

    // Changing the tree by swapping left and right pointers at every node
    root = swapLRPointers(root);

    // Searching for a value (e.g., searching for 6)
    int searchValue = 6;
    struct Node* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("Value %d is found in the tree.\n", searchValue);
    } else {
        printf("Value %d is not found in the tree.\n", searchValue);
    }

    return 0;
}
