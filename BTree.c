#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

struct BTreeNode {
    int keys[MAX + 1];
    struct BTreeNode* children[MAX + 1];
    int numKeys;
    int leaf;
};

struct BTreeNode* createNode(int leaf) {
    struct BTreeNode* node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    node->leaf = leaf;
    node->numKeys = 0;
    for (int i = 0; i < MAX + 1; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void traverse(struct BTreeNode* root) {
    if (root == NULL) return;
    
    int i;
    for (i = 0; i < root->numKeys; i++) {
        if (!root->leaf) {
            traverse(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }

    if (!root->leaf) {
        traverse(root->children[i]);
    }
}

struct BTreeNode* search(struct BTreeNode* root, int key) {
    int i = 0;
    while (i < root->numKeys && key > root->keys[i]) {
        i++;
    }
    if (i < root->numKeys && key == root->keys[i]) {
        return root;
    }
    if (root->leaf) {
        return NULL;
    }
    return search(root->children[i], key);
}

void splitChild(struct BTreeNode* parent, int i, struct BTreeNode* fullChild) {
    struct BTreeNode* newNode = createNode(fullChild->leaf);
    newNode->numKeys = MIN - 1;

    for (int j = 0; j < MIN - 1; j++) {
        newNode->keys[j] = fullChild->keys[j + MIN];
    }

    if (!fullChild->leaf) {
        for (int j = 0; j < MIN; j++) {
            newNode->children[j] = fullChild->children[j + MIN];
        }
    }

    fullChild->numKeys = MIN - 1;

    for (int j = parent->numKeys; j >= i + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    parent->children[i + 1] = newNode;

    for (int j = parent->numKeys - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = fullChild->keys[MIN - 1];

    parent->numKeys++;
}

void insertNonFull(struct BTreeNode* node, int key) {
    int i = node->numKeys - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;
        if (node->children[i]->numKeys == MAX) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

void insert(struct BTreeNode** root, int key) {
    struct BTreeNode* r = *root;

    if (r->numKeys == MAX) {
        struct BTreeNode* s = createNode(0);
        *root = s;
        s->children[0] = r;
        splitChild(s, 0, r);
        insertNonFull(s, key);
    } else {
        insertNonFull(r, key);
    }
}

int main() {
    struct BTreeNode* root = createNode(1);

    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);

    printf("B-Tree Traversal: ");
    traverse(root);
    printf("\n");

    int searchKeys[] = {6, 15, 20};
    for (int i = 0; i < 3; i++) {
        struct BTreeNode* found = search(root, searchKeys[i]);
        if (found != NULL) {
            printf("Value %d found in the B-Tree.\n", searchKeys[i]);
        } else {
            printf("Value %d not found in the B-Tree.\n", searchKeys[i]);
        }
    }

    return 0;
}
