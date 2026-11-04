// q4_is_bst.c - Check whether a given binary tree is a BST or not
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Every node must lie strictly between min and max allowed by its ancestors
int isBSTUtil(struct Node* r, long min, long max) {
    if (!r) return 1;
    if (r->data <= min || r->data >= max) return 0;
    return isBSTUtil(r->left, min, r->data) && isBSTUtil(r->right, r->data, max);
}

int isBST(struct Node* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    /* Tree 1 (valid BST):    50           Tree 2 (not a BST):   50
                             /  \                                /  \
                           30    70                            30    70
                          / \                                 / \
                        20   40                             20   60   <- 60 > 50 but is in left subtree */
    struct Node* t1 = newNode(50);
    t1->left = newNode(30);  t1->right = newNode(70);
    t1->left->left = newNode(20);  t1->left->right = newNode(40);

    struct Node* t2 = newNode(50);
    t2->left = newNode(30);  t2->right = newNode(70);
    t2->left->left = newNode(20);  t2->left->right = newNode(60);

    printf("Tree 1 is BST? %s\n", isBST(t1) ? "Yes" : "No");
    printf("Tree 2 is BST? %s\n", isBST(t2) ? "Yes" : "No");
    return 0;
}
