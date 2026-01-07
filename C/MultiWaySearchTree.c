#include <stdio.h>
#include <stdlib.h>

#define Max 4

struct Node {
    int count;
    int values[Max + 1];
    struct Node* children[Max + 1];
};

struct Node* createNode() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->count = 0;
    for (int i = 0; i <= Max; i++) {
        newNode->values[i] = 0;
        newNode->children[i] = NULL;
    }

    return newNode;
}

// Function to insert a value into the multiway search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        struct Node* newNode = createNode();
        newNode->count = 1;
        newNode->values[1] = value;
        return newNode;
    }

    int i = root->count;
    while (i > 0 && value < root->values[i]) {
        i--;
    }

    if (i > 0 && value == root->values[i]) {
        // Duplicate value, handle accordingly
        return root;
    }

    if (root->count < Max) {
        // Node has space, insert value
        i = root->count;
        while (i > 0 && value < root->values[i]) {
            root->values[i + 1] = root->values[i];
            root->children[i + 1] = root->children[i];
            i--;
        }
        root->values[i + 1] = value;
        root->count++;
    } else {
        // Node is full, split and insert
        int mid = (Max + 1) / 2;
        struct Node* temp = createNode();

        temp->count = Max - mid;
        for (int j = 1; j <= temp->count; j++) {
            temp->values[j] = root->values[mid + j];
            temp->children[j] = root->children[mid + j];
        }

        root->count = mid - 1;

        if (value < root->values[mid]) {
            root->children[root->count + 1] = temp;
            insert(root, value);
        } else {
            root->children[root->count + 1] = temp;
            insert(temp, value);
        }
    }

    return root;
}

// Function to traverse and print the multiway search tree in-order
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        for (int i = 0; i < root->count; i++) {
            inOrderTraversal(root->children[i]);
            printf("%d ", root->values[i + 1]);
        }
        inOrderTraversal(root->children[root->count]);
    }
}

// Function to free the memory allocated for the multiway search tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        for (int i = 0; i <= root->count; i++) {
            freeTree(root->children[i]);
        }
        free(root);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert values into the multiway search tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 10);

    // Print the multiway search tree
    printf("In-order traversal of the multiway search tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Free the memory allocated for the multiway search tree
    freeTree(root);

    return 0;
}