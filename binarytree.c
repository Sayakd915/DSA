#include <stdio.h>
#include <stdlib.h>

#define MAX 15

void insert(int tree[], int *n, int value) {
    if (*n >= MAX) {
        printf("Binary Tree is full\n");
        return;
    }
    tree[*n] = value;
    (*n)++;
}

void inorderTraversal(int tree[], int n, int index) {
    if (index >= n) return;
    inorderTraversal(tree, n, 2 * index + 1);
    printf("%d ", tree[index]);
    inorderTraversal(tree, n, 2 * index + 2);
}

void preorderTraversal(int tree[], int n, int index) {
    if (index >= n) return;
    printf("%d ", tree[index]);
    preorderTraversal(tree, n, 2 * index + 1);
    preorderTraversal(tree, n, 2 * index + 2);
}

void postorderTraversal(int tree[], int n, int index) {
    if (index >= n) return;
    postorderTraversal(tree, n, 2 * index + 1);
    postorderTraversal(tree, n, 2 * index + 2);
    printf("%d ", tree[index]);
}

int main() {
    int binaryTree[MAX];
    int n = 0;

    insert(binaryTree, &n, 10);
    insert(binaryTree, &n, 5);
    insert(binaryTree, &n, 20);
    insert(binaryTree, &n, 3);
    insert(binaryTree, &n, 8);
    insert(binaryTree, &n, 15);
    insert(binaryTree, &n, 30);

    printf("In-order Traversal: ");
    inorderTraversal(binaryTree, n, 0);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorderTraversal(binaryTree, n, 0);
    printf("\n");

    printf("Post-order Traversal: ");
    postorderTraversal(binaryTree, n, 0);
    printf("\n");

    return 0;
}
