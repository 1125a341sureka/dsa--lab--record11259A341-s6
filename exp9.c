#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(const struct Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(const struct Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(const struct Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void freeTree(struct Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    struct Node *root = NULL;
    int n;
    int value;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid number of nodes.\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) {
            printf("Invalid node value.\n");
            freeTree(root);
            return EXIT_FAILURE;
        }
        root = insert(root, value);
    }

    printf("\nIn-order traversal: ");
    inorder(root);
    printf("\nPre-order traversal: ");
    preorder(root);
    printf("\nPost-order traversal: ");
    postorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
