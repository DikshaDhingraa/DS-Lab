// q3_bst_insert_delete_depth.c - BST: insert (no duplicates), delete, maximum depth, minimum depth
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->left = n->right = NULL;
    return n;
}

// (a) Insert - duplicates are ignored
struct Node* insert(struct Node* r, int v) {
    if (!r) return newNode(v);
    if (v < r->data) r->left = insert(r->left, v);
    else if (v > r->data) r->right = insert(r->right, v);
    else printf("%d already exists, duplicates not allowed.\n", v);
    return r;
}

struct Node* findMin(struct Node* r) {
    while (r->left) r = r->left;
    return r;
}

// (b) Delete
struct Node* deleteNode(struct Node* r, int key) {
    if (!r) { printf("%d not found.\n", key); return NULL; }
    if (key < r->data) r->left = deleteNode(r->left, key);
    else if (key > r->data) r->right = deleteNode(r->right, key);
    else {
        if (!r->left) { struct Node* t = r->right; free(r); return t; }
        if (!r->right) { struct Node* t = r->left; free(r); return t; }
        struct Node* s = findMin(r->right);     // in-order successor
        r->data = s->data;
        r->right = deleteNode(r->right, s->data);
    }
    return r;
}

// (c) Maximum depth (number of nodes on the longest root-to-leaf path)
int maxDepth(struct Node* r) {
    int l, rt;
    if (!r) return 0;
    l = maxDepth(r->left);
    rt = maxDepth(r->right);
    return 1 + (l > rt ? l : rt);
}

// (d) Minimum depth (number of nodes on the shortest root-to-leaf path)
int minDepth(struct Node* r) {
    int l, rt;
    if (!r) return 0;
    if (!r->left) return 1 + minDepth(r->right);
    if (!r->right) return 1 + minDepth(r->left);
    l = minDepth(r->left);
    rt = minDepth(r->right);
    return 1 + (l < rt ? l : rt);
}

void inorder(struct Node* r) {
    if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); }
}

int main() {
    struct Node* root = NULL;
    int ch, v;
    do {
        printf("\n--- BST Menu ---\n1. Insert\n2. Delete\n3. Maximum depth\n"
               "4. Minimum depth\n5. Display (in-order)\n0. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &v); root = insert(root, v); break;
            case 2: printf("Value to delete: "); scanf("%d", &v); root = deleteNode(root, v); break;
            case 3: printf("Maximum depth = %d\n", maxDepth(root)); break;
            case 4: printf("Minimum depth = %d\n", minDepth(root)); break;
            case 5: if (root) { inorder(root); printf("\n"); } else printf("Tree is empty.\n"); break;
            case 0: printf("Bye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 0);
    return 0;
}
