// q2_bst_functions.c - BST: search (recursive & non-recursive), max, min, in-order successor & predecessor
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

struct Node* insert(struct Node* r, int v) {
    if (!r) return newNode(v);
    if (v < r->data) r->left = insert(r->left, v);
    else if (v > r->data) r->right = insert(r->right, v);
    return r;
}

// (a) Search - recursive
struct Node* searchRec(struct Node* r, int key) {
    if (!r || r->data == key) return r;
    if (key < r->data) return searchRec(r->left, key);
    return searchRec(r->right, key);
}

// (a) Search - non-recursive
struct Node* searchIter(struct Node* r, int key) {
    while (r && r->data != key)
        r = (key < r->data) ? r->left : r->right;
    return r;
}

// (b) Maximum element
struct Node* findMax(struct Node* r) {
    if (!r) return NULL;
    while (r->right) r = r->right;
    return r;
}

// (c) Minimum element
struct Node* findMin(struct Node* r) {
    if (!r) return NULL;
    while (r->left) r = r->left;
    return r;
}

// (d) In-order successor of the node having value key
struct Node* successor(struct Node* root, int key) {
    struct Node *succ = NULL, *cur = root;
    while (cur) {
        if (key < cur->data) { succ = cur; cur = cur->left; }
        else if (key > cur->data) cur = cur->right;
        else {
            if (cur->right) return findMin(cur->right);
            return succ;
        }
    }
    return NULL;   // key not found
}

// (e) In-order predecessor of the node having value key
struct Node* predecessor(struct Node* root, int key) {
    struct Node *pred = NULL, *cur = root;
    while (cur) {
        if (key > cur->data) { pred = cur; cur = cur->right; }
        else if (key < cur->data) cur = cur->left;
        else {
            if (cur->left) return findMax(cur->left);
            return pred;
        }
    }
    return NULL;
}

void show(const char* label, struct Node* n) {
    if (n) printf("%s %d\n", label, n->data);
    else printf("%s none\n", label);
}

int main() {
    struct Node* root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80}, i, key;
    for (i = 0; i < 7; i++) root = insert(root, vals[i]);

    printf("Enter value to search: ");
    scanf("%d", &key);
    printf("Recursive search    : %s\n", searchRec(root, key) ? "Found" : "Not found");
    printf("Non-recursive search: %s\n", searchIter(root, key) ? "Found" : "Not found");

    show("Maximum element:", findMax(root));
    show("Minimum element:", findMin(root));

    printf("Enter value for successor/predecessor: ");
    scanf("%d", &key);
    if (!searchRec(root, key)) printf("%d is not in the tree.\n", key);
    else {
        show("In-order successor  :", successor(root, key));
        show("In-order predecessor:", predecessor(root, key));
    }
    return 0;
}
