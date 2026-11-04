// q1_tree_traversals.c - Pre-order, In-order, Post-order traversals (recursive)
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

void preorder(struct Node* r)  { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void inorder(struct Node* r)   { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void postorder(struct Node* r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

int main() {
    /*        1
             / \
            2   3
           / \
          4   5      */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Pre-order : "); preorder(root);  printf("\n");
    printf("In-order  : "); inorder(root);   printf("\n");
    printf("Post-order: "); postorder(root); printf("\n");
    return 0;
}
