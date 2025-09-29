#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the BST
struct Node {
    int data;               // Value of the node
    struct Node* left;      // Pointer to the left child
    struct Node* right;     // Pointer to the right child
};

// Function to create a new node with a given value
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        // Tree is empty, so create a new node as root
        return createNode(value);
    }

    // If value is smaller, insert in left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    // If value is greater or equal, insert in right subtree
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// In-order traversal: Left -> Root -> Right
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal: Root -> Left -> Right
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal: Left -> Right -> Root
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a key in the BST
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;   // Key not found

    if (root->data == key)
        return 1;   // Key found

    if (key < root->data)
        return search(root->left, key);   // Search in left subtree
    else
        return search(root->right, key);  // Search in right subtree
}

// Function to free all allocated memory of the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    struct Node* root = NULL;   // Initialize root
    int n, value, key;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input elements and insert them into the BST
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Display traversals
    printf("\nIn-order traversal: ");
    inorder(root);

    printf("\nPre-order traversal: ");
    preorder(root);

    printf("\nPost-order traversal: ");
    postorder(root);
    printf("\n");

    // Search for a key
    printf("Enter key to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Key %d found in the tree.\n", key);
    else
        printf("Key %d not found in the tree.\n", key);

    // Free all allocated memory
    freeTree(root);

    return 0;
}
